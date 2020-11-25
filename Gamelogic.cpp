#include "Gamelogic.h"
#include "Player.h"
#include "vector_math.h"

#include <iostream>

#include "random.h"

class Asteroid {
public:
    Circle drawable;
    sf::Vector2f velocity;

    Asteroid()
        // replaced rand with mt19937, might need polish for smoother experience
        : drawable((randomGen(0, 1280)), (randomGen(0, 720)), 10, Color::Green)
        , velocity((randomGen(50, 100) % 20) - 10, (randomGen(50, 100) % 20) - 10) {
    }

    void update(Game& game, float dt) {
        drawable.pos += velocity * dt;
        ensure_boundaries(drawable.pos, game.screen_size());
        game.draw(drawable);
    }
};

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
