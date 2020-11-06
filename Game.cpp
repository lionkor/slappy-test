#include "Game.h"

// what we use here is called a "member initializer list"
Game::Game(const std::string& title)
    : m_window(sf::VideoMode(1280, 720), title) {
    m_window.setFramerateLimit(60);
}

int Game::run() {
    if (init) {
        init(*this);
    }
    while (m_running) {
        // clear/fill screen with 50% red
        m_window.clear(Color::White);
        if (update) {
            update(*this);
        }
        while (!m_rendering_queue.empty()) {
            auto& drawable = m_rendering_queue.front();
            m_window.draw(*drawable);
            m_rendering_queue.pop();
        }
        m_window.display();

        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::Escape)) {
                m_running = false;
            }
        }
    }
    if (deinit) {
        deinit(*this);
    }
    return 0;
}

void Game::draw_rectangle(float x, float y, float width, float height, Color color) {
    auto rect_ptr = std::make_unique<sf::RectangleShape>(sf::Vector2f { width, height });
    rect_ptr->setPosition(x, y);
    rect_ptr->setFillColor(color);
    m_rendering_queue.push(std::move(rect_ptr));
}

void Game::draw_rectangle(const Rectangle& rect) {
    draw_rectangle(rect.x, rect.y, rect.width, rect.height, rect.color);
}

Rectangle::Rectangle(float x, float y, float width, float height, Color color)
    : x(x)
    , y(y)
    , width(width)
    , height(height)
    , color(color) {}
