#pragma once
#include <SFML/Graphics.hpp>
#include "LineCollider.h"

class Line
{
public :
	bool isActive;
	LineCollider collider;
private:
	float stamina;
	float maxStamina;
	sf::Vector2f* playerOne;
	sf::Vector2f* playerTwo;
	sf::Vertex line[2];
	sf::RectangleShape healthBar;

public:
	Line(sf::Vector2f& playerOne, sf::Vector2f& playerTwo);
	void Update(sf::Event& event, float time);
	void Draw(sf::RenderWindow& window);
};