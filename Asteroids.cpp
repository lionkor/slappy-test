#include "Asteroids.h"
#include "Player.h"



void init(Game&) {
    //player.draw();
}

void update(Game& game, float dt) {

    player.update(game, dt);
    player.draw(game);

    //game.draw(rect);
}

void deinit(Game&) {
    //Player::~Player();
}
