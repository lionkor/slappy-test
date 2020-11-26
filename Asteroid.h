#ifndef ASTEROID_H
#define ASTEROID_H

#include "Game.h"
#include "random.h"
#include "vector_math.h"

class Asteroid {
public:
    Circle drawable;
    sf::Vector2f velocity;

    float distToPlayer { 0 };
    
    Asteroid()
        // TODO: replaced rand with mt19937, might need polish for smoother experience
        : drawable((randomGen(0, 1280)), (randomGen(0, 720)), 10, Color::Green)
        , velocity((randomGen(50, 100) % 20) - 10, (randomGen(50, 100) % 20) - 10) {
    }

    void update(Game& game, float dt) {
        drawable.pos += velocity * dt;
        ensure_boundaries(drawable.pos, game.screen_size());
        game.draw(drawable);
    }
};

#endif // ASTEROID_H