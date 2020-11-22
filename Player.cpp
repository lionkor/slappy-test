#include "Player.h"
#include "Game.h"

#define _USE_MATH_DEFINES
#include <math.h>

Player newPlayer = createPlayer();

Player createPlayer() {
    Player player;
    return player;
}


Player::Player() {
    // Setting player to middle of the screen
    // FIXME: make it to refer to player's object not rect
    drawable.pos.x = Game::SCREEN_WIDTH / 2.0f;
    drawable.pos.y = Game::SCREEN_HEIGHT / 2.0f;
    drawable.height = 10.0f;
    drawable.width = 10.0f;
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
    float rotX = (cosf(rotationInRadians) * normDirection.x) - (sinf(rotationInRadians) * normDirection.y);
    float rotY = (sinf(rotationInRadians) * normDirection.x) + (cosf(rotationInRadians) * normDirection.y);
    sf::Vector2f rotatedNormDirection(rotX, rotY);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        newPlayer.pos += (rotatedNormDirection * newPlayer.moveSpeed) * dt;
    }
}