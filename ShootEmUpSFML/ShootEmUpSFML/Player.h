#pragma once
#include "Object.h"

enum PlayerNumber {
    PLAYER1,
    PLAYER2,
};

class Player : public Object
{
    public:
	    int life;
        PlayerNumber player;
        CircleShape triangle;
        Color color;

        void Update(float time);
        void Controls(float time, PlayerNumber playerNumber);
        void UpdatePlayerPos(float time, Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey);
        void Draw(RenderWindow& window);

        Player(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life, PlayerNumber _player,Color _color);
};

