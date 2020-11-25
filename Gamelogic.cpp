#include "Gamelogic.h"
#include "Asteroid.h"
#include "Player.h"
#include "vector_math.h"

#include <cmath>

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

    // Basic collision
    // Implemented using vector distance from player
    // FIXME: Only for one asteroid instead of all of them
    // FIXME: The calculation is possibly wrong because there is a bug when player simply dissapears, even though it hasn't touched anything
    for (size_t i = 0; i < asteroid_count; i++) {
        asteroids->distToPlayer = sqrtf(powf((player->drawable.pos.x - asteroids->drawable.pos.x), 2.0f) + powf((player->drawable.pos.y - asteroids->drawable.pos.y), 2.0f));

        // Base equation for distance
        // sqrtf(powf(asteroids->drawable.pos.x - player->drawable.pos.x)) + (powf(asteroids->drawable.pos.y - player->drawable.pos.y));

        if (asteroids->distToPlayer <= 15.0f) {
            player->is_dead = true;
        }
    }

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
