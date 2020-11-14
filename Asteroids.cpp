#include "Asteroids.h"

Rectangle rect;
Circle circle;

void init(Game&) {
    rect = Rectangle(10, 10, 200, 200, Color::Green);
    circle = Circle(30, 30, 10, Color::Red);
}

float change = 50.0f;

// dt is "delta time", its the time (in seconds) it took to render the last frame.
// you use this to make movement independent of framerate.
// for example, moving a rectange by '50 * dt' will move it by 50 pixels per second.
// just think of '* dt' of 'per second'.
void update(Game& game, float dt) {
    // rect moves my 50 pixels every second
    rect.x += 50.0f * dt;
    game.draw(rect);

    // this is the change that is defined earlier in the file, multiplied by dt to make it framerate-independent.
    float actual_change = change * dt;
    // we change the radius of the circle by this change. the change is already adjusted for framerate, of course.
    circle.radius = circle.radius + actual_change;
    // if its grown beyond 120, we reverse the change, so instead of adding to the radius, we subtract.
    // we reverse it again once the circle is small enough.
    if (circle.radius > 120 || circle.radius < 10) {
        change = -change;
    }
    game.draw(circle);
}

void deinit(Game&) {
}
