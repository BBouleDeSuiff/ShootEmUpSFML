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

    void Update(float time);
    void Controls(PlayerNumber playerNumber);
    void UpdatePlayerPos(Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey);

    Player(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life, PlayerNumber _player);

};

