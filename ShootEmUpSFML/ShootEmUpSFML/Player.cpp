#include "Player.h"
#include <iostream>

Player::Player(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life, PlayerNumber _player,  Color _color) :Object(_position, _scale, _angle, _speed)
{
    player = _player;
    life = 1;
    triangle = sf::CircleShape(1* _scale.x,3);
    triangle.setOutlineThickness(3);
    triangle.setOutlineColor(_color);
    triangle.setFillColor(Color::Black);
    triangle.setOrigin(1 * _scale.x, 1 * _scale.x); //Set anchor point to triangle's center
    color = _color;
}

void Player::Update(float time) {
    Controls(time, player);
}

void Player::Controls(float time, PlayerNumber playerNumber) {
    switch (playerNumber) {
        case PlayerNumber::PLAYER1:
            UpdatePlayerPos(time, Keyboard::Q, Keyboard::D, Keyboard::Z, Keyboard::S);
            break;
        case PlayerNumber::PLAYER2:
            UpdatePlayerPos(time, Keyboard::Left, Keyboard::Right, Keyboard::Up, Keyboard::Down);
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
void Player::Draw(RenderWindow &window) {
    this->triangle.setPosition(this->position);
    this->triangle.setRotation(this->angle);
    window.draw(triangle);
}
