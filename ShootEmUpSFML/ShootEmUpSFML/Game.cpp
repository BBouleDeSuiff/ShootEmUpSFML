#include "Game.h"
#include <iostream>

Game::Game()
{
	score = 0;
    time = clock.getElapsedTime().asSeconds();
	playerOne = new Player(sf::Vector2f(50, 100), sf::Vector2f(10, 10), 0., 3., 1, PlayerNumber::PLAYER1);
	playerTwo = new Player(sf::Vector2f(180, 100), sf::Vector2f(10, 10), 0, 3,1, PlayerNumber::PLAYER2);
    line = new Line();
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
        std::cout << time << std::endl;
        clock.restart();
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        playerOne->Update(time);
        playerTwo->Update(time);
        for (Object& enemy : enemies) {
            enemy.Update(time);
        }
        window.clear();
        // Whatever I want to draw goes here

        window.display();
    }
}
