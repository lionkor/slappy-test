#include "Gamelogic.h"
#include "Asteroid.h"
#include "Player.h"
#include "vector_math.h"

#include <cmath>

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
    player = new Player(game);
    asteroids = new Asteroid[asteroid_count];
}

void update(Game& game, float dt) {

    for (size_t i = 0; i < asteroid_count; ++i) {
        // Collision with asteroids
        asteroids[i].distToPlayer = std::sqrtf(std::pow((asteroids[i].drawable.pos.x - player->drawable.pos.x), 2.0f) + std::pow((asteroids[i].drawable.pos.y - player->drawable.pos.y), 2.0f));

        if (asteroids[i].distToPlayer <= 16.0f) {
            player->is_dead = true;
        }

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
