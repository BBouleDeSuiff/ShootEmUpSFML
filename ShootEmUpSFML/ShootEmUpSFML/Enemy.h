#pragma once
#include "Player.h"
#include "Planet.h"
#include "Line.h"

class Enemy : public Object
{
	private:
		Line* line;
		Vector2f direction;

	public:
		Player* playerOne;
		Player* playerTwo;
		Planet* planet;
		CircleShape shape;
		Object* target;

		int score;

		Enemy(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet, Line& _line);
		~Enemy();

		virtual void Update(float time, int& score);
		void Draw(RenderWindow& window);
};

