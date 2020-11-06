#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include <string>

class Game {
private:
    sf::RenderWindow m_window;
    bool m_running { true };

public:
    Game(const std::string& title);

    int run();
};

#endif // GAME_H
