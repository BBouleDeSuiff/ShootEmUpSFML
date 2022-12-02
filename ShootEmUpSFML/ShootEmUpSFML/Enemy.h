#pragma once
#include "Player.h"
class Enemy : public Object
{
public:
	Player* playerOne;
	Player* playerTwo;
	Enemy(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& p1, Player& p2);
	void Update(float time);
};

