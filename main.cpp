#include "Gamelogic.h"
#include "Game.h"

int main() {
    // dont touch
    Game game("Asteroids");
    game.init = init;
    game.update = update;
    game.deinit = deinit;
    return game.run();
}
