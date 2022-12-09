#include "GameOver.h"
#include "SFML/Graphics.hpp"
#include "Button.h"

GameOver::GameOver()
{
    play = Button(sf::Vector2f(400,300), sf::Vector2f(200,100),sf::Color::Red,sf::Color::White,24,"Play");
	reload = false;
	isOver = false;
	quit = false;
}

void GameOver::GameOverUpdate(sf::RenderWindow& window)
{
	window.clear(sf::Color::Black);
    play.UpdateAndDraw(window);
    reload = play.isClicked;
}
