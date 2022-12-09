#include "DeathEnemyParticle.h"

DeathEnemyParticle::DeathEnemyParticle(float lifetime, float startSize, sf::Vector2f enemyPosition) : Particle(lifetime)
{
	shape.setOrigin(startSize, startSize);
	shape.setRadius(startSize);
	shape.setOutlineThickness(1.f);
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
	shape.setScale(newScale, newScale);
}
