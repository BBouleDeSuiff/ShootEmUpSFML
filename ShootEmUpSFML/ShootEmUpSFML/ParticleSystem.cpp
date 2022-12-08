// ConteneurSTD.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "ParticleSystem.h"
using namespace std;



ParticleSystem::ParticleSystem(float creationDurationInterval, float minParticleLifeTime, float maxParticleLifeTime, Vector2f _origin, float _spawnRadius, float _startSize) {

	particleList = new std::list<Particle> ;

	spawnTimer = 0;
	spawnDurationInterval = creationDurationInterval;
	minLifeTime = minParticleLifeTime;
	maxLifeTime = maxParticleLifeTime;
	origin = _origin;
	spawnRadius = _spawnRadius;
	startSize = _startSize;
}
void ParticleSystem::AddParticle(float lifetime) {
	Particle particle = { lifetime };

	particle.shape.setRadius(10);
	particle.shape.setOrigin(10, 10);

	const float PI = 3.14159265;
	float angle = PI * 2.0f * (float)rand() / RAND_MAX;
	float distance = 10 * sqrt((float)rand() / RAND_MAX);
	float x = this->origin.x + cos(angle) * distance;
	float y = this->origin.y + sin(angle) * distance;

	particle.shape.setPosition(x, y);

	(*particleList).push_back(particle);
}

void ParticleSystem::Update(float elapsedDeltaTime) {
	std::list<Particle>::iterator it = (*particleList).begin();
	this->spawnTimer += elapsedDeltaTime;
	const float PI = 3.14159265;
	while (spawnTimer > spawnDurationInterval) {
		float lifeTime = minLifeTime + (maxLifeTime - minLifeTime) * (float)rand() / RAND_MAX;
		AddParticle(lifeTime);
		spawnTimer -= spawnDurationInterval;
		it = (*particleList).begin();
		while (it != (*particleList).end()) {
			float scale = sin(PI * it->elapsedTime / it->lifeTime);
			it->shape.setScale(scale, scale);
			it->elapsedTime += elapsedDeltaTime;
			if (it->elapsedTime > it->lifeTime) {
				it = (*particleList).erase(it);
				continue;
			}
			it++;
		}
	}
}
void ParticleSystem::Clear() {
	spawnTimer = 0;
	(*particleList).clear();
}
void ParticleSystem::Draw(RenderWindow& window) {
	for (Particle particle : (*particleList))
	{
		window.draw(particle.shape);
	}
}
