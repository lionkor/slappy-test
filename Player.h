#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"

class Player {

public:
    unsigned int m_posX;
    unsigned int m_posY;

    const double m_speed = 2.0;

public:
    Player() {
        // Setting player position to middle of the screen
        m_posX = Game::SCREEN_WIDTH / 2;
        m_posY = Game::SCREEN_HEIGHT / 2;
    };

    // 1. Desconstruct when game is closed
    // 2. Deconstruct when player dies, maybe use new operator for player?
    ~Player() {};

public:
    Rectangle draw();
};

#endif // PLAYER_H