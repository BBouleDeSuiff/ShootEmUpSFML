// ConteneurSTD.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "ParticleSystem.h"
using namespace std;



ParticleSystem::ParticleSystem(float creationDurationInterval, float minParticleLifeTime, float maxParticleLifeTime, Vector2f _origin, float _spawnRadius, float _startSize, CircleShape* _playerShape) {

	particleList = new std::list<Particle> ;

	spawnTimer = 0;
	spawnDurationInterval = creationDurationInterval;
	minLifeTime = minParticleLifeTime;
	maxLifeTime = maxParticleLifeTime;
	origin = _origin;
	spawnRadius = _spawnRadius;
	startSize = _startSize;
	playerShape = _playerShape;
}
void ParticleSystem::AddParticle(float lifetime) {
	Particle particle = { lifetime };

	//particle.shape.setRadius(10);
	particle.shape.setSize(Vector2f(1 * startSize, 10 * startSize));
	particle.shape.setOrigin(10, 10);
	particle.shape.setRotation(playerShape->getRotation());

	const float PI = 3.14159265;
	float angle = PI * 2.0f * (float)rand() / RAND_MAX;
	float distance = 10 * sqrt((float)rand() / RAND_MAX);
	float x = this->origin.x + cos(angle) * distance;
	float y = this->origin.y + sin(angle) * distance;

	particle.shape.setPosition(x, y);

	(*particleList).push_back(particle);
}

void ParticleSystem::AddEnemyDeathParticles(float lifetime,sf::Vector2f scale, sf::Vector2f position)
{
	Particle particle = { lifetime };
	particle.shape.setSize(Vector2f(startSize*10, startSize*10));
	particle.shape.setOrigin(scale.x/2., scale.y / 2.);

	particle.shape.setPosition(position.x,position.y);

	(*particleList).push_back(particle);
}



void ParticleSystem::Update(float deltaTime) {
	std::list<Particle>::iterator it = (*particleList).begin();
	this->spawnTimer += deltaTime;
	const float PI = 3.14159265;
	if (spawnTimer >= spawnDurationInterval) {
		float lifeTime = minLifeTime + (maxLifeTime - minLifeTime) * (float)rand() / RAND_MAX;
		AddParticle(lifeTime);
		spawnTimer = 0;
	}
	it = (*particleList).begin();
	while (it != (*particleList).end()) {
		float scale = sin(PI * it->elapsedTime / it->lifeTime);
		it->shape.setScale(scale, scale);
		it->elapsedTime += deltaTime;
		if (it->elapsedTime > it->lifeTime) {
			it = (*particleList).erase(it);
			continue;
		}
		it++;
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
