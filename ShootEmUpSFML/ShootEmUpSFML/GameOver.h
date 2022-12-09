#pragma once
#include "Game.h"
#include "Button.h"

class GameOver
{
public:
	bool isOver;
	bool quit;
	bool reload;
	Button play;
	GameOver();
	void GameOverUpdate(sf::RenderWindow& window);
};
