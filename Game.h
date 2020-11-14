#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <functional>
#include <queue>
#include <string>

using Color = sf::Color;

struct Shape {
    float x { 0 };
    float y { 0 };
    Color fill_color { Color::White };
    float rotation { 0 };
    Shape(float _x, float _y, Color _fill_color, float _rotation = 0);
    Shape() = default;
};

struct Rectangle final : public Shape {
    float width { 10 };
    float height { 10 };

    Rectangle(float _x, float _y, float _width, float _height, Color _fill_color = Color::White);
    Rectangle() = default;
};

struct Circle final : public Shape {
    float radius;
    Circle(float _x, float _y, float _radius, Color _fill_color = Color::White);
    Circle() = default;
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
    std::function<void(Game&, float)> update { nullptr };
    std::function<void(Game&)> deinit { nullptr };

    void draw(const Rectangle& rect);
    void draw(const Circle& circle);
};

#endif // GAME_H
