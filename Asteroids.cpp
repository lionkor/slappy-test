#include "Asteroids.h"
#include "Player.h"

sf::ConvexShape convex;

void init(Game&) {
    Player player;
    // player.draw();

    convex.setPointCount(5);

    // Tried playing around with Convex shapes, since it would perfectly allow us to make the player model.
    // Player's middle point used for spawning
    convex.setPoint(0, sf::Vector2f(0.f, 0.f));

    convex.setPoint(1, sf::Vector2f(150.f, 10.f));
    convex.setPoint(2, sf::Vector2f(120.f, 90.f));
    convex.setPoint(3, sf::Vector2f(30.f, 100.f));
    convex.setPoint(4, sf::Vector2f(0.f, 50.f));

}

// float change = 50.0f;

// dt is "delta time", its the time (in seconds) it took to render the last frame.
// you use this to make movement independent of framerate.
// for example, moving a rectange by '50 * dt' will move it by 50 pixels per second.
// just think of '* dt' of 'per second'.
void update(Game& game, float dt) {
    // rect moves my 50 pixels every second
// rect.x += 50.0f * dt;
//game.draw(rect);

    game.draw(convex);

}


void deinit(Game&) {
}
