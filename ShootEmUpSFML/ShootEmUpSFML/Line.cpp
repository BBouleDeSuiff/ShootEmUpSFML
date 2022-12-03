#include "Line.h"

Line::Line(sf::Vector2f& playerOne, sf::Vector2f& playerTwo) {
	isActive = false;
	this->playerOne = &playerOne;
	this->playerTwo = &playerTwo;
	line[0] = sf::Vertex(playerOne);
	line[1] = sf::Vertex(playerTwo);	
	collider = LineCollider(playerOne, playerTwo);
}
void Line::Update(sf::Event &event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		isActive = true;
		line[0] = sf::Vertex(*(this->playerOne));
		line[1] = sf::Vertex(*(this->playerTwo));
	} else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
		isActive = false;
	}
}

void Line::Draw(sf::RenderWindow& window)
{
	if (isActive) {
		window.draw(line, 2, sf::Lines);
	}
}

