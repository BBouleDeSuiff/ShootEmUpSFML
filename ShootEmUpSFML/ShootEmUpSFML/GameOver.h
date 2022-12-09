#pragma once
#include "Game.h"
#include "Button.h"

class GameOver
{
	private:
		Text scoreTxt;
		Text gameOverTitle;
		Font font;
	public:
		bool isOver;
		int score;
		Button playButton;
		Button quitButton;

	GameOver();
	void GameOverUpdate(sf::RenderWindow& window, int _score);
	void DrawScore(sf::Vector2f _pos, sf::RenderWindow& window);
	void DrawGameOverTitle(sf::Vector2f _pos, sf::RenderWindow& window);
};
