#pragma once
#include "Object.h"
#include "Player.h"
#include "Planet.h"
#include "Line.h"
#include "Enemy.h"
#include <list>

class Game
{
	private :
		float time; //Delta time between two frames
		Player* playerOne;
		Player* playerTwo;
		Planet* planet;

		Line* line;
		std::list<Enemy> enemies;
		sf::RenderWindow window;
		sf::Clock clock;

	public :
		int score;

		Game();
		~Game();

		void Update();
};

