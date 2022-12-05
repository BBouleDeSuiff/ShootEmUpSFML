#include "Game.h"
#include <iostream>

sf::Vector2f GetRandomOutsidePos(int spawnMargin) {
    int randomSide = rand() % 1 + 0;
    switch (randomSide) {
        case 0:
            int choices[2] = { 0 - spawnMargin, 800 + spawnMargin };
            int x = choices[rand() % 1 + 0];
            int y = rand() % (600 + spawnMargin) + (0 - spawnMargin);
            return(*(new Vector2f(x, y)));
        case 1:
            int choices[2] = { 0 - spawnMargin, 600 + spawnMargin };
            int x = rand() % (800 + spawnMargin) + (0 - spawnMargin);
            int y = choices[rand() % 1 + 0]; 
            return(*(new Vector2f(x, y)));
    }
}

void SpawnEnemies(std::list<Enemy*> &enemyLists, Player& playerOne, Player& playerTwo, Planet& planet, int numberOfEnemies, int spawnMargin) {
    int randInt = rand() % 10 + 1;
    for (int i = 0; i < numberOfEnemies; i++) {
        if (randInt <= 8)
            enemyLists.push_back(new Soldier(GetRandomOutsidePos(spawnMargin), sf::Vector2f(30, 30), 0, 100, playerOne, playerTwo, planet));
        else
            enemyLists.push_back(new Assassin(GetRandomOutsidePos(spawnMargin), sf::Vector2f(30, 30), 0, 100, playerOne, playerTwo, planet));
    }
}

void Game::StartEnemyWaves() {
    timer += time;
    if (timer > 5) {
        SpawnEnemies(enemies, *playerOne, *playerTwo, *planet, enemiesNumber, spawnMargin);
        enemiesNumber++;
        timer = 0;
    }
}

Game::Game()
{
	score = 0;
    time = clock.getElapsedTime().asSeconds();
	playerOne = new Player(sf::Vector2f(400, 200), sf::Vector2f(30, 30), 0, 200, 1, PlayerNumber::PLAYER1, Color::Blue);
	playerTwo = new Player(sf::Vector2f(500, 300), sf::Vector2f(30, 30), 0, 200, 1, PlayerNumber::PLAYER2, Color::Red);
    planet = new Planet(sf::Vector2f(400, 300), sf::Vector2f(30, 30), 25);
    line = new Line(playerOne->position,playerTwo->position);
	window.create(sf::VideoMode(800, 600), "SFMLMotherHuger");
}

Game::~Game()
{
	delete playerOne;
	delete playerTwo;
}

void Game::Update()
{
    // Game loop
    while (window.isOpen()) {
        time = clock.getElapsedTime().asSeconds();
        //std::cout << time << std::endl;
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            //"close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        playerOne->Update(time);
        playerTwo->Update(time);
        planet->Update(time);
        line->Update(event);

        for (Enemy* &enemy : enemies)
        {
            enemy->Update(time);
        }

        window.clear(sf::Color::Black);
        // Whatever I want to draw goes here
        playerOne->Draw(window);
        playerTwo->Draw(window);
        line->Draw(window);
        planet->AnimateAndDraw(window);

        window.display();
    }
}
