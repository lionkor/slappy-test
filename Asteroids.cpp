#include "Asteroids.h"
#include "Player.h"

#include <cmath>

Rectangle rect;

void init(Game&) {

    rect.pos.x = Game::SCREEN_WIDTH / 2.0;
    rect.pos.y = Game::SCREEN_HEIGHT / 2.0f;

    rect.texture.loadFromFile("resources/cat.jpg");

    //Player player;
    // player.draw();
}

static float length(const sf::Vector2f& vec) {
    return std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

static sf::Vector2f normalized(const sf::Vector2f& vec) {
    return vec / length(vec);
}

const float moveSpeed = 150.0f;
// dt is "delta time", its the time (in seconds) it took to render the last frame.s
// you use this to make movement independent of framerate.
// for example, moving a rectange by '50 * dt' will move it by 50 pixels per second.
// just think of '* dt' of 'per second'.
void update(Game& game, float dt) {

    // IDEA: moveSpeed increases to a certain max as long as player is holding it down, decreases when he lets go by dt?

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.rotation -= 3.5f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.rotation += 3.5f;
    }

    // 1. Base vector
    sf::Vector2f direction(0.0f, -1.0f);
    // 2. Vector length of direction
    // 3. Normalized vector(direction)
    sf::Vector2f normDirection = normalized(direction);

    // New rotationPosition's calculated by using the Rotation Matrix formula for 2d vector
    // IMPORTANT: This is ONLY for counter-clockswise rotation
    float rotationInRadians = rect.rotation * M_PI / 180.0f;
    float rotX = (cosf(rotationInRadians) * normDirection.x) - (sinf(rotationInRadians) * normDirection.y);
    float rotY = (sinf(rotationInRadians) * normDirection.x) + (cosf(rotationInRadians) * normDirection.y);
    sf::Vector2f rotatedNormDirection(rotX, rotY);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        // Basic movement is done! \o/
        rect.pos += (rotatedNormDirection * moveSpeed) * dt;
    }

    game.draw(rect);
}

void deinit(Game&) {
}
