#include "Asteroids.h"
#include "Player.h"

#include <cmath>

Rectangle rect;

void init(Game&) {

    rect.x = Game::SCREEN_HEIGHT / 2;
    rect.y = Game::SCREEN_WIDTH / 2;

    //Player player;
    // player.draw();
}

// dt is "delta time", its the time (in seconds) it took to render the last frame.s
// you use this to make movement independent of framerate.  
// for example, moving a rectange by '50 * dt' will move it by 50 pixels per second.
// just think of '* dt' of 'per second'.
void update(Game& game, float dt) {
 
    // IDEA: moveSpeed increases to a certain max as long as player is holding it down, decreases when he lets go by dt?

    // 1. Base vector
    sf::Vector2f direction(1.0f, 1.0f);
    // 2. Vector length of direction
    float directionLength = std::sqrt((direction.x * direction.x) + (direction.y * direction.y));
    // 3. Normalized vector(direction)
    sf::Vector2f normDirection = (direction / directionLength);

    const float moveSpeed = 150.0f;

    const float rotationDegree = 7.5f;

    // New rotationPosition's calculated by using the Rotation Matrix formula for 2d vector
    // IMPORTANT: This is ONLY for counter-clockswise rotation
    float ctrClkWiseRotX = (cos(rotationDegree) * normDirection.x) + (sin(rotationDegree) * normDirection.y);
    float ctrClkWiseRotY = (sin(rotationDegree) * normDirection.x) + (cos(rotationDegree) * normDirection.y);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // Basic movement is done! \o/
        rect.y -= (normDirection.y * moveSpeed) * dt;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.rotation -= 7.5f;
        normDirection.x = ctrClkWiseRotX;
        normDirection.y = ctrClkWiseRotY;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.rotation += 7.5f;
        // TODO: Implement clockwise rotation here
        normDirection.x = rotationPositionX;
        normDirection.y = rotationPositionY;
    }

    game.draw(rect);
}

void deinit(Game&) {
}
