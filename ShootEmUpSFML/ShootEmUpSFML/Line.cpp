#include "Line.h"

Line::Line(sf::Vector2f& playerOne, sf::Vector2f& playerTwo) {
	maxStamina = 10.;
	stamina = maxStamina;
	isActive = false;
	this->playerOne = &playerOne;
	this->playerTwo = &playerTwo;
	line[0] = sf::Vertex(playerOne);
	line[1] = sf::Vertex(playerTwo);	
	collider = LineCollider(playerOne, playerTwo);
	healthBar.setSize(sf::Vector2f(200,30));
	healthBar.setPosition(sf::Vector2f(10,10));
	healthBar.setFillColor(sf::Color::Green);
	//healthBar.setPosition(sf::Vector2f());
}
void Line::Update(sf::Event& event, float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && stamina > 0.) {
		isActive = true;
		line[0] = sf::Vertex(*(this->playerOne));
		line[1] = sf::Vertex(*(this->playerTwo));
		stamina -= time * 2;
		if (stamina <= 0.) {
			isActive = false;
		}
	} else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
		isActive = false;
	}
	if (!isActive && stamina <= maxStamina) {
		stamina += time * 3;
	}
	healthBar.setSize(sf::Vector2f(200 * stamina /maxStamina, 30));
}

void Line::Draw(sf::RenderWindow& window)
{
	if (isActive) {
		window.draw(line, 2, sf::Lines);
	}
	window.draw(healthBar);
}

