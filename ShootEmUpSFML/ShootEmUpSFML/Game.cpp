#include "Game.h"

Game::Game()
{
	score = 0;
	time = 0;
	playerOne = new Player(sf::Vector2f(50, 100), sf::Vector2f(10, 10), 0., 3., 1, PlayerNumber::PLAYER1);
	playerTwo = new Player(sf::Vector2f(180, 100), sf::Vector2f(10, 10), 0, 3,1, PlayerNumber::PLAYER2);
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
        sf::Event event;
        while (window.pollEvent(event)) {
            // Process any input event here
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        playerOne->Update(time);
        playerTwo->Update(time);

        window.clear();
        // Whatever I want to draw goes here
        window.display();
    }
}
