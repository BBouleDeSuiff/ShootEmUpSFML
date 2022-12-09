#include "Game.h"
#include <iostream>

sf::Vector2f Game::GetRandomOutsidePos(int spawnMargin) {
    int randomSide;
    randomSide = rand() % 2;

    int choices[2];
    int x = 0;
    int y = 0;
    choices[0] = 0 - spawnMargin;
    switch (randomSide) {
        case 0:
            choices[1] = windowWidth + spawnMargin;
            x = choices[rand() % 2 + 0];
            y = rand() % (windowHeight + spawnMargin) + (0 - spawnMargin);
            break;
        case 1:
            choices[1] = windowHeight + spawnMargin;
            x = rand() % (windowWidth + spawnMargin) + (0 - spawnMargin);
            y = choices[rand() % 2 + 0]; 
            break;
    }
    return(*(new Vector2f(x, y)));
}


void Game::SpawnEnemies(std::list<Enemy*> &enemyLists, Player& playerOne, Player& playerTwo, Planet& planet, Line& line, int numberOfEnemies, int spawnMargin, int speed) {
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

Game::Game()
{
    srand(time(NULL));
	score = 0;
    deltaTime = clock.getElapsedTime().asSeconds();
    playerOne = new Player(sf::Vector2f(400, 200), sf::Vector2f(15, 15), 0, 200, 1, PlayerNumber::PLAYER1, Color::Blue, 0.15f, 0.25f, 1.f, 20, 10);
	playerTwo = new Player(sf::Vector2f(500, 300), sf::Vector2f(15, 15), 0, 200, 1, PlayerNumber::PLAYER2, Color::Red, 0.15f, 0.25f, 1.f, 20, 10);
    players.push_back(playerOne);
    players.push_back(playerTwo);
    planet = new Planet(sf::Vector2f(400, 300), sf::Vector2f(30, 30), 25);
    line = new Line(playerOne->position,playerTwo->position);
    UI = new UIElements(playerOne, playerTwo, &score);
	window.create(sf::VideoMode(windowWidth, windowHeight), "SFMLMotherHuger");
}

void Game::UpdateObjects(Event event) 
{
    planet->Update(deltaTime);
    line->Update(event, deltaTime);
    UI->Update();

    StartEnemyWaves();

    for (Player*& player : players)
    {
        player->particleSystem->Update(deltaTime);
        player->Update(deltaTime);
    }
        playerOne->Update(deltaTime);
        playerTwo->Update(deltaTime);
        planet->Update(deltaTime);
        line->Update(event,deltaTime);
        StartEnemyWaves();

    std::list<Enemy*>::iterator it = enemies.begin();
    while (it != enemies.end())
    {
        if ((*it)->isDead)
        {
            playerOne->particleSystem->AddEnemyDeathParticles(1, (*it)->scale, (*it)->position);
            it = enemies.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void Game::Draw(RenderWindow& window) 
{
    planet->AnimateAndDraw(window);
    line->Draw(window);

    for (Player*& player : players)
    {
        player->particleSystem->Draw(window);
        player->Draw(window);
    }
    for (Enemy* enemy : enemies)
    {
        enemy->Draw(window);
    }
    UI->Draw(window);
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

        UpdateObjects(event);

        window.clear(sf::Color::Black);

        // Whatever I want to draw goes here
        Draw(window);

        window.display();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
    {
        isOver = true;
    }
}

Game::~Game()
{
    delete playerOne->particleSystem->particleList;
    delete playerTwo->particleSystem->particleList;

    delete playerOne->particleSystem;
    delete playerTwo->particleSystem;

    delete playerOne;
    delete playerTwo;
    delete planet;
    delete line;

    std::list<Enemy*>::iterator it = enemies.begin();
    while (it != enemies.end())
    {
        delete *it;
        it++;
    }
}