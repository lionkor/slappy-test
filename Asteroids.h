#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include "Game.h"

// called before the game starts. use this to initialize and prepare.
void init(Game& game);

// called on each frame.
void update(Game& game);

// called right before the game closes.
void deinit(Game& game);

#endif // ASTEROIDS_H
