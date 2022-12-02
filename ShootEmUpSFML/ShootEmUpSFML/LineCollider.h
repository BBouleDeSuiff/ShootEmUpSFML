#pragma once
#include <SFML/Graphics.hpp>


class LineCollider
{
public:
	sf::Vector2f* a;
	sf::Vector2f* b;
	LineCollider(sf::Vector2f& playerOne, sf::Vector2f& playerTwo);
};
