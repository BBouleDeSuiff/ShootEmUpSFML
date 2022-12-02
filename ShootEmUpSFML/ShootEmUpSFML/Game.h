#pragma once
#include "Object.h"
#include "Line.h"
#include <list>

class Game
{
	private :
		float time; //Delta time between two frames
		Object playerOne;
		Object playerTwo;
		Line line;
		std::list<Object> enemies;
		sf::RenderWindow window;

	public :
		int score;

		Game();
		~Game();

		void Update();
};

