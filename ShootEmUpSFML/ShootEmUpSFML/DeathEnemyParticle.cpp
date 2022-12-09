#include "DeathEnemyParticle.h"

DeathEnemyParticle::DeathEnemyParticle(float lifetime, float startSize, sf::Vector2f enemyPosition) : Particle(lifetime)
{
	shape.setScale(startSize * 2, startSize * 2);
	shape.setOrigin(10, 10);
	shape.setOutlineThickness(1.5f);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::Cyan);
	shape.setPosition(enemyPosition.x, enemyPosition.y);
}

void DeathEnemyParticle::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void DeathEnemyParticle::SetScale(float newScale)
{
	shape.setScale(newScale, newScale);
}
