#include "GameOver.h"
#include "SFML/Graphics.hpp"
#include "Button.h"

GameOver::GameOver()
{
	playButton = Button(sf::Vector2f(400, 350), sf::Vector2f(200, 75), sf::Color::Red, sf::Color::White, 32, "Play");
	quitButton = Button(sf::Vector2f(400,450), sf::Vector2f(200, 75),sf::Color::Blue,sf::Color::White, 32, "Quit");
	isOver = false;
	font.loadFromFile("retroGaming.ttf");
}

void GameOver::GameOverUpdate(sf::RenderWindow& window,int _score)
{
	score = _score;
	window.clear(sf::Color::Black);
	playButton.UpdateAndDraw(window);
	quitButton.UpdateAndDraw(window);
	DrawScore(sf::Vector2f(300, 205),window);
	DrawGameOverTitle(sf::Vector2f(260, 150), window);
}

void GameOver::DrawScore(sf::Vector2f _pos, sf::RenderWindow& window)
{
	scoreTxt.setPosition(_pos);
	scoreTxt.setFont(font);
	scoreTxt.setString("Score : " + std::to_string(score));
	scoreTxt.setCharacterSize(24);
	scoreTxt.setFillColor(sf::Color::White);

	window.draw(scoreTxt);
}

void GameOver::DrawGameOverTitle(sf::Vector2f _pos, sf::RenderWindow& window)
{
	gameOverTitle.setPosition(_pos);
	gameOverTitle.setFont(font);
	gameOverTitle.setString("GameOver");
	gameOverTitle.setCharacterSize(46);
	gameOverTitle.setFillColor(sf::Color::White);

	window.draw(gameOverTitle);
}
