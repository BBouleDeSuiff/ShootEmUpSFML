#include "Player.h"

Player::Player(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life, PlayerNumber _player,  Color _color, float _particleSpawnInterval, float _minParticleLifeTime, float maxParticleLifeTime, float _particleSpawnRadius, float _particleStartSize) :Object(_position, _scale, _angle, _speed)
{
    player = _player;
    life = 1;
    triangle = sf::CircleShape(1 * _scale.x, 3);
    triangle.setOutlineThickness(3);
    triangle.setOutlineColor(_color);
    triangle.setFillColor(Color::Black);
    triangle.setOrigin(1 * _scale.x, 1 * _scale.x); //Set anchor point to triangle's center
    color = _color;
    particleSystem = new ParticleSystem(_particleSpawnInterval, _minParticleLifeTime, maxParticleLifeTime, _position, _particleSpawnRadius, _particleStartSize, &triangle);
    keyStates = std::vector<bool>(4, false);
}
void Player::Normalize(Vector2f& vector) {
    float norm = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (norm != 0)
        vector = vector / norm;
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

void Player::UpdatePlayerRot(sf::Vector2f directionVector)
{
    if (directionVector.y != 0 || directionVector.x != 0) {
        this->angle = (int)(atan2(directionVector.y, directionVector.x) * 180 / 3.1415 + 90);
    }
}

void Player::CheckOutOfBounds()
{
    if (this->position.x < -triangle.getScale().x) {
        this->position.x = this->position.x + 800 + triangle.getScale().x;
    }
    if (this->position.x > 800 + triangle.getScale().x) {
        this->position.x = this->position.x - 800 - triangle.getScale().x;
    }
    if (this->position.y < -triangle.getScale().y) {
        this->position.y = this->position.y + 600 + triangle.getScale().y;
    }
    if (this->position.y > 600 + triangle.getScale().y) {
        this->position.y = this->position.y - 600 - triangle.getScale().y;
    }
}

void Player::UpdatePlayerPos(float time, Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey) {
    sf::Vector2f directionVector;
    if (sf::Keyboard::isKeyPressed(leftKey)) {
        directionVector.x += -1;
    }
    if (sf::Keyboard::isKeyPressed(rightKey)) {
        directionVector.x += 1;
    }
    if (sf::Keyboard::isKeyPressed(downKey)) {
        directionVector.y += 1;
    }
    if (sf::Keyboard::isKeyPressed(upKey)) {
        directionVector.y += -1;
    }
    UpdatePlayerRot(directionVector);
    CheckOutOfBounds();
    Normalize(directionVector);
    this->position.x += this->speed * time * directionVector.x;
    this->position.y += this->speed * time * directionVector.y;
    particleSystem->origin = position;
}

void Player::Draw(RenderWindow &window) {
    this->triangle.setPosition(this->position);
    this->triangle.setRotation(this->angle);
    window.draw(triangle);
}
