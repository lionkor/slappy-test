#include "Gamelogic.h"
#include "Player.h"
#include "vector_math.h"

#include <iostream>

#include "Asteroid.h"

// heap allocate for the heck of it
Player* player { nullptr };
Asteroid* asteroids { nullptr };
size_t asteroid_count { 5 };

void resize_asteroids_to(size_t new_size) {
    Asteroid* new_asteroids = new Asteroid[new_size];
    for (size_t i = 0; i < asteroid_count; ++i) {
        new_asteroids[i] = asteroids[i];
    }
    delete[] asteroids;
    asteroids = new_asteroids;
    asteroid_count = new_size;
}

void init(Game& game) {
    //srand(time(nullptr));
    player = new Player(game);
    asteroids = new Asteroid[asteroid_count];
}

void update(Game& game, float dt) {
    for (size_t i = 0; i < asteroid_count; ++i) {
        asteroids[i].update(game, dt);
    }
    player->update(game, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        resize_asteroids_to(asteroid_count + 1);
    }
}

void deinit(Game&) {
    delete[] asteroids;
    delete player;
}
