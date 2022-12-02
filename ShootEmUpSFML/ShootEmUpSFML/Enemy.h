#pragma once
#include "Object.h"

class Enemy : public Object
{
    int life;
    CircleShape shape;

    public:
        void Update(float time);
        void UpdatePlayerPos(float time, Keyboard::Key leftKey, Keyboard::Key rightKey, Keyboard::Key downKey, Keyboard::Key upKey);

    Enemy(Vector2f _position, Vector2f _scale, float _angle, float _speed, int _life);

};

