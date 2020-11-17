#include "Asteroids.h"
#include "Player.h"

Rectangle rect;

void init(Game&) {
    //Player player;
    // player.draw();
}

// float change = 50.0f;

// dt is "delta time", its the time (in seconds) it took to render the last frame.
// you use this to make movement independent of framerate.
// for example, moving a rectange by '50 * dt' will move it by 50 pixels per second.
// just think of '* dt' of 'per second'.
void update(Game& game, float dt) {
    // rect moves my 50 pixels every second

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.x -= 50.0f * dt;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.x += 50.0f * dt;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rect.y -= 50.0f * dt;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rect.y += 50.0f * dt;
    }

    // reeeeeeeeeeeeeeeeeeeeeeeeee
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        rect.rotation += 5.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        rect.rotation -= 5.f;
    }

    game.draw(rect);
    //rect.x += 50.0f * dt;
}

void deinit(Game&) {
}
