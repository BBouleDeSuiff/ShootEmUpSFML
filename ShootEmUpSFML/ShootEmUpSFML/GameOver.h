#pragma once
#include "Game.h"
#include "Button.h"

class GameOver
{
public:
	bool isOver;
	int score;
	Button playButton;
	Button quitButton;
	Text scoreTxt;
	Font font;
	GameOver();
	void GameOverUpdate(sf::RenderWindow& window, int _score);
	void DrawScore(sf::Vector2f _pos, sf::RenderWindow& window);
};
