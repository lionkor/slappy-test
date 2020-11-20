#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"

//FIXME: If player is to be seen, we are missing the width and height variables from Rectangle!!!

static class Player final : public Shape {

public:
    const float moveSpeed = 150.0f;

    // TODO: Need to add width and height from sf::ConvexShape when we get around that
    // Cuz player atm has no visual representation

public:
    Player();
    ~Player();

public:

    Rectangle draw(Game& game);

    void update(Game& game, float dt);
};

#endif // PLAYER_H