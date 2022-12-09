#include "DeathEnemyParticle.h"

DeathEnemyParticle::DeathEnemyParticle(float lifetime, float startSize, sf::Vector2f enemyPosition) : Particle(lifetime)
{
	shape.setScale(startSize, startSize);
	shape.setOutlineThickness(0.1f);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::Yellow);
	shape.setPosition(enemyPosition.x, enemyPosition.y);
}

void DeathEnemyParticle::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void DeathEnemyParticle::SetScale(float newScale)
{
	shape.setRadius(newScale);
}
