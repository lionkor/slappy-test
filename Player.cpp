#include "Player.h"
#include "Game.h"

#define _USE_MATH_DEFINES
#include <math.h>

Player player;

Player::Player() {
    // Setting player to middle of the screen
    // FIXME: make it to refer to player's object not rect
    player.pos.x = Game::SCREEN_WIDTH / 2.0f;
    player.pos.y = Game::SCREEN_HEIGHT / 2.0f;
}

Player::~Player() {

}

// Vector length
static float length(const sf::Vector2f& vec) {
    return std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

// Vector normalization
static sf::Vector2f normalized(const sf::Vector2f& vec) {
    return vec / length(vec);
}

Rectangle draw(Game& game, Rectangle& rect, Player& player) {
    rect.width = 10;
    rect.height = 10;

    return rect;
}

Player update(Game& game, float dt,) {

    sf::Vector2f direction(0.0f, -1.0f);

    sf::Vector2f normDirection = normalized(direction);

    //FIXME: rect should be changed to player.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.rotation -= 3.5f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.rotation += 3.5f;
    }

    float rotationInRadians = player.rotation * M_PI / 180.0f;
    float rotX = (cosf(rotationInRadians) * normDirection.x) - (sinf(rotationInRadians) * normDirection.y);
    float rotY = (sinf(rotationInRadians) * normDirection.x) + (cosf(rotationInRadians) * normDirection.y);
    sf::Vector2f rotatedNormDirection(rotX, rotY);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.pos += (rotatedNormDirection * player.moveSpeed) * dt;
    }

    return player;
}