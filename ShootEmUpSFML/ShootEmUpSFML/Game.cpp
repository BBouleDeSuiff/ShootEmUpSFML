#include "Game.h"
#include <iostream>

Game::Game()
{
	score = 0;
    time = clock.getElapsedTime().asSeconds();
	playerOne = new Player(sf::Vector2f(400, 200), sf::Vector2f(30, 30), 0, 200, 1, PlayerNumber::PLAYER1, Color::Blue);
	playerTwo = new Player(sf::Vector2f(500, 300), sf::Vector2f(30, 30), 0, 200, 1, PlayerNumber::PLAYER2, Color::Red);
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

        for (Enemy &enemy : enemies)
        {
            enemy.Update(time);
        }

        window.clear(sf::Color::Black);
        // Whatever I want to draw goes here
        playerOne->Draw(window);
        playerTwo->Draw(window);

        RectangleShape testRectangle;
        window.draw(testRectangle);
        window.display();
    }
}
