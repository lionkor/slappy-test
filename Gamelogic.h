#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "Game.h"

#include "Player.h"

// called before the game starts. use this to initialize and prepare.
void init(Game& game);

// called on each frame.
void update(Game& game, float dt);

// called right before the game closes.
void deinit(Game& game);

#endif // GAMELOGIC_H
