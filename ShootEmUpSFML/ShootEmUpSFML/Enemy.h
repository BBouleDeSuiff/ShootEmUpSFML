#pragma once
#include "Player.h"
#include "Planet.h"
#include "Line.h"

class Enemy : public Object
{

	public:
		int score;

		Player* playerOne;
		Player* playerTwo;
		Planet* planet;
		Line* line;

		Object* target;
		Vector2f direction;

		CircleShape shape;

		virtual void Update(float time, int& score);
		void Draw(RenderWindow& window);

		Enemy(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet, Line& _line);
		~Enemy();
};

