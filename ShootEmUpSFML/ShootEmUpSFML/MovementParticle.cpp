#include "MovementParticle.h"

MovementParticle::MovementParticle(float lifetime,float startSize, sf::Vector2f position, float playerRotation) : Particle(lifetime)
{
	shape.setSize(sf::Vector2f(startSize,startSize));
	shape.setOrigin(10, 10);
	shape.setRotation(playerRotation);
	shape.setOutlineThickness(1.5f);
	shape.setFillColor(sf::Color::Black);
	shape.setPosition(position.x, position.y);
}

void MovementParticle::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void MovementParticle::SetScale(float newScale)
{
	shape.setScale(newScale, newScale);
}
