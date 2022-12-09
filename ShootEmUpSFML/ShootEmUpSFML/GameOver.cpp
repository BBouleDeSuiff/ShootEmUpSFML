#include "GameOver.h"
#include "SFML/Graphics.hpp"
#include "Button.h"

GameOver::GameOver()
{
	playButton = Button(sf::Vector2f(400, 300), sf::Vector2f(200, 100), sf::Color::Red, sf::Color::White, 24, "Play");
	quitButton = Button(sf::Vector2f(400,400), sf::Vector2f(200,100),sf::Color::Blue,sf::Color::White,24,"Quit");
	isOver = false;
}

void GameOver::GameOverUpdate(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
	playButton.UpdateAndDraw(window);
	quitButton.UpdateAndDraw(window);
}
