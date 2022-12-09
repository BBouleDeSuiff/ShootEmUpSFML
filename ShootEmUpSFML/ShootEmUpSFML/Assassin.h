#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Planet.h"

class Assassin : public Enemy
{
	private:
		void ResetTarget();
	public:
		Assassin(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet, Line& _line);
		void Update(float time, int& score);
};