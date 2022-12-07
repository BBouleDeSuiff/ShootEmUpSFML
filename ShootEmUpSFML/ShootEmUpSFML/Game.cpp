#include "Game.h"
#include <iostream>

sf::Vector2f GetRandomOutsidePos(int spawnMargin) {
    int randomSide;
    randomSide = rand() % 2;
    /*for (int i=0; i < 10; i++) {
        std::cout << rand() % 2 << std::endl;
    }*/

    int *choices;
    int x;
    int y ;

    switch (randomSide) {
        case 0:
            choices = new int[2] { (0 - spawnMargin), (800 + spawnMargin) };
            x = choices[rand() % 2 + 0];
            y = rand() % (600 + spawnMargin) + (0 - spawnMargin);

            /*std::cout << "x ="<< x << std::endl;
            std::cout << "y =" << y << std::endl;*/

            return(*(new Vector2f(x, y)));
        case 1:
            choices = new int[2] { 0 - spawnMargin, 600 + spawnMargin };
            x = rand() % (800 + spawnMargin) + (0 - spawnMargin);
            y = choices[rand() % 2 + 0]; 

            /*std::cout << "x =" << x << std::endl;
            std::cout << "y =" << y << std::endl;*/

            return(*(new Vector2f(x, y)));
    }
}


void SpawnEnemies(std::list<Enemy*> &enemyLists, Player& playerOne, Player& playerTwo, Planet& planet, Line& line, int numberOfEnemies, int spawnMargin, int speed) {
    for (int i = 0; i < numberOfEnemies; i++) {
        int randInt = rand() % 10 + 1;
        if (randInt <= 8)
            enemyLists.push_back(new Soldier(GetRandomOutsidePos(spawnMargin), sf::Vector2f(15, 15), 0, speed, playerOne, playerTwo, planet, line));
        else
            enemyLists.push_back(new Assassin(GetRandomOutsidePos(spawnMargin), sf::Vector2f(15, 15), 0, speed, playerOne, playerTwo, planet, line));
    }
}

void Game::StartEnemyWaves() {
    timer += deltaTime;
    //std::cout << timer << std::endl;
    if (timer > 6) {
        SpawnEnemies(enemies, *playerOne, *playerTwo, *planet, *line, enemiesNumber, spawnMargin, enemiesSpeed);
        //std::cout << enemies.size() << std::endl;
        enemiesNumber+= 0.25f;
        enemiesSpeed += 2;
        timer = 0;
    }
}

void Game::DrawEnemies() {
    for (Enemy* enemy : enemies)
    {
        enemy->Draw(window);
    }
}

Game::Game()
{
    srand(time(NULL));
	score = 0;
    deltaTime = clock.getElapsedTime().asSeconds();
	playerOne = new Player(sf::Vector2f(400, 200), sf::Vector2f(15, 15), 0, 200, 1, PlayerNumber::PLAYER1, Color::Blue);
	playerTwo = new Player(sf::Vector2f(500, 300), sf::Vector2f(15, 15), 0, 200, 1, PlayerNumber::PLAYER2, Color::Red);
    planet = new Planet(sf::Vector2f(400, 300), sf::Vector2f(30, 30), 25);
    line = new Line(playerOne->position,playerTwo->position);
	window.create(sf::VideoMode(800, 600), "SFMLMotherHuger");
}
void Game::Update()
{
    // Game loop
    while (window.isOpen()) {
        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            //"close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        playerOne->Update(deltaTime);
        playerTwo->Update(deltaTime);
        planet->Update(deltaTime);
        line->Update(event,deltaTime);
        StartEnemyWaves();

        for (Enemy* &enemy : enemies)
        {
            enemy->Update(deltaTime, score);
        }

        window.clear(sf::Color::Black);
        // Whatever I want to draw goes here
        line->Draw(window);
        playerOne->Draw(window);
        playerTwo->Draw(window);
        
        planet->AnimateAndDraw(window);
        DrawEnemies();
        std::list<Enemy*>::iterator it = enemies.begin();
        while (it != enemies.end())
        {
            if ((*it)->isDead)
            {
                it = enemies.erase(it);
            }
            else
            {
                it++;
            }
        }
        window.display();
    }
}

Game::~Game()
{
    delete playerOne;
    delete playerTwo;
}