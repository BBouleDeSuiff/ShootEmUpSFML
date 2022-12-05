#pragma once
#include "LineCollider.h"

class Line
{
public :
	Line(sf::Vector2f& playerOne, sf::Vector2f& playerTwo);
	void Update(sf::Event &event,float time);
	void Draw(sf::RenderWindow& window);
private:
	float stamina;
	bool isActive;
	LineCollider collider;
	sf::Vector2f* playerOne;
	sf::Vector2f* playerTwo;
	sf::Vertex line[2];

};