#include "GameOver.h"
#include "SFML/Graphics.hpp"
#include "Button.h"

GameOver::GameOver()
{
	playButton = Button(sf::Vector2f(400, 350), sf::Vector2f(200, 75), sf::Color::Red, sf::Color::White, 32, "Play");
	quitButton = Button(sf::Vector2f(400,450), sf::Vector2f(200, 75),sf::Color::Blue,sf::Color::White, 32, "Quit");
	isOver = false;
}

void GameOver::GameOverUpdate(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	playButton.UpdateAndDraw(window);
	quitButton.UpdateAndDraw(window);
}
