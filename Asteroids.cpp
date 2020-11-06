#include "Asteroids.h"

Rectangle rect;

void init(Game& game) {
    rect = Rectangle(10, 10, 200, 200, Color::Green);
}

void update(Game& game) {
    rect.x += 1.0;
    game.draw_rectangle(rect);
}

void deinit(Game& game) {
}
