#pragma once
#include "Object.h"
#include "Player.h"
#include "Planet.h"
#include "Line.h"
#include "Enemy.h"
#include "Soldier.h"
#include "Assassin.h"
#include "UIElements.h"
#include <list>

class Game
{
	private :
		float deltaTime; //Delta time between two frames
		Player* playerOne;
		Player* playerTwo;
		std::list<Player*> players;
		Planet* planet;
		Line* line;

		std::list<Enemy*> enemies;
		float enemiesNumber = 1; // Number of enemies per wave
		float enemiesSpeed = 70;
		const float spawnMargin = 30; // How far enemies spawn outside of screen
		float timer = 0;

		UIElements* UI;

		sf::Clock clock;

		void SpawnEnemies(std::list<Enemy*>& enemyLists, Player& playerOne, Player& playerTwo, Planet& planet, Line& line, int numberOfEnemies, int spawnMargin, int speed);

		void StartEnemyWaves();

		void UpdateObjects(Event event);
		void Draw(RenderWindow& window);

		sf::Vector2f GetRandomOutsidePos(int spawnMargin);

	public :
		int score;
		bool isOver;
		int windowWidth = 800;
		int windowHeight = 600;
		Game();
		~Game();
		void Update(sf::Event event, RenderWindow& window);
};