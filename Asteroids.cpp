#include "Asteroids.h"
#include "Player.h"

Rectangle rect;

// Not sure if this is what we want to use here
Player* player = new Player();

void init(Game&) {
    player.draw();
}

void update(Game& game, float dt) {

    player.update(game, dt);
    player.draw();
    //game.draw(rect);

    game.draw(rect);
}

void deinit(Game&) {
    //Player::~Player();
}
