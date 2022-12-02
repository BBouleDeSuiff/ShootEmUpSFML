#include "Player.h"

Player::Player(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life, PlayerNumber _player,  Color _color) :Object(_position, _scale, _angle, _speed)
{
    player = _player;
    life = 1;
    triangle = sf::CircleShape();
    triangle.setPointCount(3);
    triangle.setOutlineThickness(3);
    triangle.setOutlineColor(_color);
    color = _color;
}

void Player::Update(float time) {
    Controls(time, player);
}

void Player::Controls(float time, PlayerNumber playerNumber) {
    switch (playerNumber) {
        case PlayerNumber::PLAYER1:
            UpdatePlayerPos(time, Keyboard::Q, Keyboard::D, Keyboard::S, Keyboard::Z);
            break;
        case PlayerNumber::PLAYER2:
            UpdatePlayerPos(time, Keyboard::Left, Keyboard::Right, Keyboard::Down, Keyboard::Up);
            break;
    }
}

void Player::UpdatePlayerPos(float time, Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey) {
    this->position;
    if (sf::Keyboard::isKeyPressed(leftKey)) {
        this->position.x += -1 * this->speed * time;
        this->angle = -90;
    }
    else if (sf::Keyboard::isKeyPressed(rightKey)) {
        this->position.x += 1 * this->speed * time;
        this->angle = 90;
    }
    else if (sf::Keyboard::isKeyPressed(downKey)) {
        this->position.y -= 1 * this->speed * time;
        this->angle = 0;
    }
    else if (sf::Keyboard::isKeyPressed(upKey)) {
        this->position.y += 1 * this->speed * time;
        this->angle = 180;
    }
}
void Player::Draw() {
    this->triangle.setPosition(this->position);
    this->triangle.setRotation(this->angle);
}
