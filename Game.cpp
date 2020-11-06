#include "Game.h"

// what we use here is called a "member initializer list"
Game::Game(const std::string& title)
    : m_window(sf::VideoMode(1280, 720), title) {
}

int Game::run() {
    while (m_running) {
        // clear/fill screen with 50% red
        m_window.clear({ 128, 0, 0, 255 });
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
    return 0;
}
