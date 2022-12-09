// ConteneurSTD.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "ParticleSystem.h"
using namespace std;



ParticleSystem::ParticleSystem(float creationDurationInterval, float minParticleLifeTime, float maxParticleLifeTime, Vector2f _origin, float _spawnRadius, float _startSize, CircleShape* _playerShape) {

	spawnTimer = 0;
	spawnDurationInterval = creationDurationInterval;
	minLifeTime = minParticleLifeTime;
	maxLifeTime = maxParticleLifeTime;
	origin = _origin;
	spawnRadius = _spawnRadius;
	startSize = _startSize;
	playerShape = _playerShape;
	isEnabled = false;
}
void ParticleSystem::AddParticle(float lifetime) {

	const float PI = 3.14159265;
	float angle = PI * 2.0f * (float)rand() / RAND_MAX;
	float distance = 10 * sqrt((float)rand() / RAND_MAX);
	float x = this->origin.x + cos(angle) * distance;
	float y = this->origin.y + sin(angle) * distance;

	MovementParticle* particle = new MovementParticle(lifetime, startSize, Vector2f(x, y), playerShape->getRotation());

	particleList.push_back(particle);
}

void ParticleSystem::AddEnemyDeathParticles(float lifetime,sf::Vector2f scale, sf::Vector2f position)
{
	DeathEnemyParticle* particle = new DeathEnemyParticle(lifetime, startSize, position);
	particleList.push_back(particle);
}



void ParticleSystem::Update(float deltaTime) {
	std::list<Particle*>::iterator it = particleList.begin();
	this->spawnTimer += deltaTime;
	const float PI = 3.14159265;

	// Add particles // 

	if (isEnabled) {
		if (spawnTimer >= spawnDurationInterval) {
			float lifeTime = minLifeTime + (maxLifeTime - minLifeTime) * (float)rand() / RAND_MAX;
			AddParticle(lifeTime);
			spawnTimer = 0;
		}
	}

	// Delete particles // 
	it = particleList.begin();
	while (it != particleList.end()) {
		float scale = sin(PI * (*it)->elapsedTime / (*it)->lifeTime);
		(*it)->SetScale(scale);
		(*it)->elapsedTime += deltaTime;
		if ((*it)->elapsedTime > (*it)->lifeTime) {
			delete* it;
			it = particleList.erase(it);
			continue;
		}
		it++;
	}
	//std::cout << "size " << particleList.size() << std::endl;
}

void ParticleSystem::Clear() {
	spawnTimer = 0;
	particleList.clear();
}

void ParticleSystem::Draw(RenderWindow& window) {
	for (Particle* particle : particleList)
	{
		particle->Draw(window);
	}
}
