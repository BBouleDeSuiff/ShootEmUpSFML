#include "Player.h"

void Player:: Update(float time) {
    
    Controls(player);

}

void Player:: Controls(PlayerNumber playerNumber) {
    switch (playerNumber) {
        case PlayerNumber::PLAYER1:
            UpdatePlayerPos(Keyboard::Q, Keyboard::D, Keyboard::S, Keyboard::Z);
            break;
        case PlayerNumber::PLAYER2:
            UpdatePlayerPos(Keyboard::Left, Keyboard::Right, Keyboard::Down, Keyboard::Up);
            break;
    }
}

void Player:: UpdatePlayerPos(Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey) {
    this->position;
    if (sf::Keyboard::isKeyPressed(leftKey)) {
        this->position.x -= 0.1f;
    }
    else if (sf::Keyboard::isKeyPressed(rightKey)) {
        this->position.x += 0.1f;
    }
    else if (sf::Keyboard::isKeyPressed(downKey)) {
        this->position.y -= 0.1f;
    }
    else if (sf::Keyboard::isKeyPressed(upKey)) {
        this->position.y += 0.1f;
    }
}


main() {

}