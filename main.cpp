#include "Game.h"
#include "Asteroids.h"

int main() {
    // dont touch
    Game game("Asteroids");
    game.init = init;
    game.update = update;
    game.deinit = deinit;
    return game.run();
}
