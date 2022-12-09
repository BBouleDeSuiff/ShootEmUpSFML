#pragma once
#include <SFML/Graphics.hpp>
class Particle
{
	public :
		float lifeTime;
		float elapsedTime = 0;
	
		Particle(float _lifeTime);
		virtual void Draw(sf::RenderWindow& window);
		virtual void SetScale(float newScale);
};

