#include "GameOver.h"
#include "SFML/Graphics.hpp"
#include "Button.h"

GameOver::GameOver()
{
	playButton = Button(sf::Vector2f(400, 300), sf::Vector2f(200, 100), sf::Color::Red, sf::Color::White, 24, "Play");
	quitButton = Button(sf::Vector2f(400,400), sf::Vector2f(200,100),sf::Color::Blue,sf::Color::White,24,"Quit");
	font.loadFromFile("../Font.otf");
	isOver = false;
}

void GameOver::GameOverUpdate(sf::RenderWindow& window,int _score)
{
	score = _score;
	window.clear(sf::Color::Black);
	playButton.UpdateAndDraw(window);
	quitButton.UpdateAndDraw(window);
	DrawScore(sf::Vector2f(0,0),window);
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
