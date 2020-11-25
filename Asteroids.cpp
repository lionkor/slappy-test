#include "Asteroids.h"
#include "Player.h"

#include <iostream>

// translation unit = cpp file

// This is truly terrible and I am sorry for my mistakes, code Jesus please forgib for my sinz.
// FIXME: Better alternative is to declare have player inside game object / game itself
Player player {};

void init(Game&) {
}

void update(Game& game, float dt) {
    player.update(game, dt);
}

void deinit(Game&) {
}
