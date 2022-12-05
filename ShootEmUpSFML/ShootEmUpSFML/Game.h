#pragma once
#include "Object.h"
#include "Player.h"
#include "Planet.h"
#include "Line.h"
#include "Enemy.h"
#include "Soldier.h"
#include "Assassin.h"
#include <list>

class Game
{
	private :
		float time; //Delta time between two frames
		Player* playerOne;
		Player* playerTwo;
		Planet* planet;

		std::list<Enemy*> enemies;
		int enemiesNumber = 1; // Number of enemies per wave
		const float spawnMargin = 20; // How far enemies spawn outside of screen
		float timer = 0;

		Line* line;
		sf::RenderWindow window;
		sf::Clock clock;


	public :
		int score;

		Game();
		~Game();

		void StartEnemyWaves();
		void Update();
};

