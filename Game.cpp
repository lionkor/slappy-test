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
    sf::Clock frame_clock;
    while (m_running) {
        // clear/fill screen with 50% red
        m_window.clear(Color::White);
        if (update) {
            update(*this, frame_clock.restart().asSeconds());
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

void Game::draw(const Circle& circle) {
    auto circle_ptr = std::make_unique<sf::CircleShape>(circle.radius);
    circle_ptr->setOrigin(circle.radius, circle.radius);
    circle_ptr->setFillColor(circle.fill_color);
    circle_ptr->setPosition(circle.x, circle.y);
    circle_ptr->setRotation(circle.rotation);
    m_rendering_queue.push(std::move(circle_ptr));
}

void Game::draw(const Rectangle& rect) {
    auto rect_ptr = std::make_unique<sf::RectangleShape>(sf::Vector2f { rect.width, rect.height });
    rect_ptr->setPosition(rect.x, rect.y);
    rect_ptr->setFillColor(rect.fill_color);
    m_rendering_queue.push(std::move(rect_ptr));
}

Rectangle::Rectangle(float _x, float _y, float _width, float _height, Color _fill_color)
    : Shape(_x, _y, _fill_color)
    , width(_width)
    , height(_height) { }

Shape::Shape(float _x, float _y, Color _fill_color, float _rotation)
    : x(_x)
    , y(_y)
    , fill_color(_fill_color)
    , rotation(_rotation) {
}

Circle::Circle(float _x, float _y, float _radius, Color _fill_color)
    : Shape(_x, _y, _fill_color)
    , radius(_radius) {
}
