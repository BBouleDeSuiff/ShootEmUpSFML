#pragma once
# include "Particle.h"
class DeathEnemyParticle : public Particle
{
	sf::CircleShape shape;
	public :
		DeathEnemyParticle(float lifetime, float startSize, sf::Vector2f enemyPosition);
		void Draw(sf::RenderWindow& window) override;
		void SetScale(float newScale) override;
};

