#pragma once
#include "Game.h"
#include "Button.h"

class GameOver
{
	public:
		bool isOver;
		Button playButton;
		Button quitButton;
		GameOver();
		void GameOverUpdate(sf::RenderWindow& window);
};
