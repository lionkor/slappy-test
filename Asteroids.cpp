#include "Asteroids.h"
#include "Player.h"

// This is truly terrible and I am sorry for my mistakes, code Jesus please forgib for my sinz.
// FIXME: Better alternative is to declare have player inside game object / game itself
extern Player player;

void init(Game&) {
    //player.draw();
}

void update(Game& game, float dt) {
    player.update(game, dt);
}

void deinit(Game&) {
    //Player::~Player();
}
