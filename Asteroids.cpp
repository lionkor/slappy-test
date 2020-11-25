#include "Asteroids.h"
#include "Player.h"
#include "vector_math.h"

#include <iostream>

// heap allocate for the heck of it
Player* player { nullptr };

void init(Game&) {
    player = new Player;
}

void update(Game& game, float dt) {
    player->update(game, dt);
}

void deinit(Game&) {
    delete player;
}
