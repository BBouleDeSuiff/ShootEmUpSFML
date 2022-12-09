// ShootEmUpSFML.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GameOver.h"

int main()
{
	Game* game = new Game();
	GameOver gameOver;

	while (game->window.isOpen() && !gameOver.quit)
	{
		sf::Event event;
		while (game->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game->window.close();
		}

		if (gameOver.isOver)
		{
			gameOver.GameOverUpdate(game->window);
			if (gameOver.reload)
			{
				delete game;
				game = new Game();
				gameOver = GameOver();
			}
		}
		else
		{
			game->Update(event);
			gameOver.isOver = game->isOver;
		}
		game->window.display();
	}


}
