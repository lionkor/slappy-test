#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <functional>
#include <queue>
#include <string>

using Color = sf::Color;

struct Rectangle {
    float x { 0 };
    float y { 0 };
    float width { 10 };
    float height { 10 };
    Color color { Color::White };

    Rectangle(float x, float y, float width, float height, Color color = Color::White);
    Rectangle() = default;
};

class Game {
private:
    sf::RenderWindow m_window;
    bool m_running { true };
    std::queue<std::unique_ptr<sf::Drawable>> m_rendering_queue;

public:
    Game(const std::string& title);

    int run();

    std::function<void(Game&)> init { nullptr };
    std::function<void(Game&)> update { nullptr };
    std::function<void(Game&)> deinit { nullptr };

    void draw_rectangle(float x, float y, float width, float height, Color color = Color::White);
    void draw_rectangle(const Rectangle& rect);
};

#endif // GAME_H
