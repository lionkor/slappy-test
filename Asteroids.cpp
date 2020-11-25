#include "Asteroids.h"
#include "Player.h"
#include "vector_math.h"

#include <iostream>

class Asteroid {
public:
    Rectangle drawable;
    sf::Vector2f velocity;

    Asteroid()
        : drawable(100 + (rand() % 600), 100 + (rand() % 600), 10, 10, Color::Green)
        , velocity() {
    }
};

// heap allocate for the heck of it
Player* player { nullptr };
Asteroid* asteroids { nullptr };
size_t asteroid_count { 5 };

void resize(size_t new_size) {
    Asteroid* new_asteroids = new Asteroid[new_size];
    for (size_t i = 0; i < asteroid_count; ++i) {
        new_asteroids[i] = asteroids[i];
    }
    delete[] asteroids;
    asteroids = new_asteroids;
    asteroid_count = new_size;
}

void init(Game&) {
    srand(time(nullptr));
    player = new Player;
    asteroids = new Asteroid[asteroid_count];
}

void update(Game& game, float dt) {
    player->update(game, dt);
    for (size_t i = 0; i < asteroid_count; ++i) {
        game.draw(asteroids[i].drawable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        resize(asteroid_count + 1);
    }
}

void deinit(Game&) {
    delete[] asteroids;
    delete player;
}
