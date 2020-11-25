#include "Player.h"
#include "Game.h"
#include "vector_math.h"

#define _USE_MATH_DEFINES
#include <math.h>

Player::Player(Game& game) {
    // Setting player to middle of the screen
    // FIXME: make it to refer to player's object not rect
    drawable.pos.x = game.screen_size().x / 2.0f;
    drawable.pos.y = game.screen_size().y / 2.0f;
    drawable.height = 10.0f;
    drawable.width = 10.0f;
}

Player::~Player() {
}

void Player::update(Game& game, float dt) {
    sf::Vector2f direction(0.0f, -1.0f);

    sf::Vector2f normDirection = normalized(direction);

    //FIXME: rect should be changed to player.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        drawable.rotation -= 3.5f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        drawable.rotation += 3.5f;
    }

    float rotationInRadians = drawable.rotation * M_PI / 180.0f;
    float rotX = (cos(rotationInRadians) * normDirection.x) - (sin(rotationInRadians) * normDirection.y);
    float rotY = (sin(rotationInRadians) * normDirection.x) + (cos(rotationInRadians) * normDirection.y);
    sf::Vector2f rotatedNormDirection(rotX, rotY);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        drawable.pos += (rotatedNormDirection * moveSpeed) * dt;
    }

    ensure_boundaries(drawable.pos, game.screen_size());

    game.draw(drawable);
}
