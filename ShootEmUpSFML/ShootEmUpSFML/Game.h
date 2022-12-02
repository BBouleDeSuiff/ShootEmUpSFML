#pragma once
#include "Object.h"
#include "Player.h"
#include "Line.h"
#include "Enemy.h"
#include <list>

class Game
{
	private :
		float time; //Delta time between two frames
		Object* playerOne;
		Object* playerTwo;
		Line line;
		std::list<Enemy> enemies;
		sf::RenderWindow window;
		sf::Clock clock;

	public :
		int score;

		Game();
		~Game();

		void Update();
};

