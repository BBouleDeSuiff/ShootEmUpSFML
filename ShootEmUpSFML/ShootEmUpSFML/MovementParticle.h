#pragma once
#include "Particle.h"

class MovementParticle : public Particle
{
	sf::RectangleShape shape;
public :
	
	MovementParticle(float lifetime, float startSize, sf::Vector2f position, float playerRotation);
	void Draw(sf::RenderWindow& window) override;
	void SetScale(float newScale) override;
};

