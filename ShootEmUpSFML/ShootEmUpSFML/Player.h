#pragma once
#include "Object.h"

enum PlayerNumber {
    PLAYER1,
    PLAYER2,
};

class Player : public Object
{
	int life;
    PlayerNumber player;
    CircleShape triangle;
    Color color;

    public:
        void Update(float time);
        void Controls(float time, PlayerNumber playerNumber);
        void UpdatePlayerPos(float time, Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey);
        void Draw();

    Player(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life, PlayerNumber _player, CircleShape _triangle, Color _color);
};

