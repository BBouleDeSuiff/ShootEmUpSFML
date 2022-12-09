// ShootEmUpSFML.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameOver.h"

int main()
{
	sf::RenderWindow window;
	Game* game = new Game();
	window.create(sf::VideoMode(game->windowWidth, game->windowHeight), "SFMLMotherHuger");
	GameOver gameOver;

	while (window.isOpen() && !gameOver.quitButton.isClicked)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (gameOver.isOver)
		{
			gameOver.GameOverUpdate(window);
			if (gameOver.playButton.isClicked)
			{
				delete game;
				game = new Game();
				gameOver = GameOver();
			}
		}
		else
		{
			game->Update(event,window);
			gameOver.isOver = game->isOver;
		}
		window.display();
	}
}
