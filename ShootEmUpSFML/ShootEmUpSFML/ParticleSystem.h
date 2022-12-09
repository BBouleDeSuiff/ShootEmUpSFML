#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include<list>
#include "Particle.h"
#include "DeathEnemyParticle.h"
#include "MovementParticle.h"
using namespace sf;

/*struct Particle {
	float lifeTime;
	float elapsedTime = 0;
	RectangleShape shape;
};*/


class ParticleSystem
{
	private:
		float spawnDurationInterval;
		float spawnTimer = 0;
		float minLifeTime;
		float maxLifeTime;
		float spawnRadius;
		float startSize;
		CircleShape* playerShape;

	public:
		std::list<Particle*> particleList;
		Vector2f origin;
		bool isEnabled;

		ParticleSystem(float creationDurationInterval, float minParticleLifeTime, float maxParticleLifeTime, Vector2f _origin, float _spawnRadius, float _startSize, CircleShape* playerShape);

		void AddParticle(float lifetime);
		void AddEnemyDeathParticles(float lifetime, sf::Vector2f scale, sf::Vector2f position);
		void Update(float elapsedDeltaTime);
		void Clear();
		void Draw(RenderWindow& window);
};


