#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include<list>
#include "Player.h"

using namespace sf;

struct Particle {
	float lifeTime;
	float elapsedTime = 0;
	RectangleShape shape;
};


class ParticleSystem
{
	public:
		std::list<Particle> *particleList;
		float spawnDurationInterval;
		float spawnTimer = 0;
		float minLifeTime;
		float maxLifeTime;
		Vector2f origin;
		float spawnRadius;
		float startSize;
		Player *player;

		ParticleSystem(float creationDurationInterval, float minParticleLifeTime, float maxParticleLifeTime, Vector2f _origin, float _spawnRadius, float _startSize, Player *_player);

		void AddParticle(float lifetime);
		void Update(float elapsedDeltaTime);
		void Clear();
		void Draw(RenderWindow& window);
};


