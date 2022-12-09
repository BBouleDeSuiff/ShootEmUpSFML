#include "Line.h"

Line::Line(sf::Vector2f& playerOne, sf::Vector2f& playerTwo) : collider(playerOne,playerTwo) {
	maxStamina = 3.;
	stamina = maxStamina;
	isActive = false;
	this->playerOne = &playerOne;
	this->playerTwo = &playerTwo;
	line[0] = sf::Vertex(playerOne);
	line[1] = sf::Vertex(playerTwo);
}
void Line::Update(sf::Event& event, float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (stamina > 0.) {
				isActive = true;
				line[0] = sf::Vertex(*(this->playerOne));
				line[1] = sf::Vertex(*(this->playerTwo));
				stamina -= time;
			}
			else {
				isActive = false;
			}
		}
		else {
			if (stamina > 0.) {
				stamina -= time;
			}
		}
	}
	if (event.type == sf::Event::KeyReleased && (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)) {
		isActive = false;
	}
	if (!isActive && stamina < maxStamina && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) {
		stamina += time * 2;
	}
}

void Line::Draw(sf::RenderWindow& window)
{
	if (isActive) {
		window.draw(line, 2, sf::Lines);
	}
}

float Line::GetStamina() {
	return stamina;
}
float Line::GetMaxStamina() {
	return maxStamina;
}

