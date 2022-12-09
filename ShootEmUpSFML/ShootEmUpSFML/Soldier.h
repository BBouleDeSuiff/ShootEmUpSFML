#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Planet.h"

class Soldier : public Enemy
{
	public:
		void Update(float time, int& score);
		Soldier(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet, Line& _line);
};