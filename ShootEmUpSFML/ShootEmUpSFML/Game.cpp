#include "Game.h"

Game::Game()
{
	score = 0;
	time = 0;
	window.create(sf::VideoMode(800, 600), "SFMLMotherHuger");
}
