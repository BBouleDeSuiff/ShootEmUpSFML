#pragma once

struct Particle {
	float lifeTime;
	float elapsedTime = 0;
};

struct ParticleSystem {
	std::list<Particle> particleList;
	float spawnDurationInterval;
	float spawnTimer = 0;
	float minLifeTime;
	float maxLifeTime;
};

ParticleSystem CreateParticleSystem(float creationDurationInterval, float minParticleLifeTime, float maxParticleLifeTime) {
	ParticleSystem particleSystem;
	particleSystem.spawnDurationInterval = creationDurationInterval;
	particleSystem.minLifeTime = minParticleLifeTime;
	particleSystem.maxLifeTime = maxParticleLifeTime;
	return(particleSystem);
}

void AddParticleToSystem(ParticleSystem& particleSystem, float lifetime) {
	Particle particle = { lifetime };
	particleSystem.particleList.push_back(particle);
}

void UpdateParticleSystem(ParticleSystem& particleSystem, float elapsedDeltaTime) {
	std::list<Particle>::iterator it = particleSystem.particleList.begin();
	particleSystem.spawnTimer += elapsedDeltaTime;
	while (particleSystem.spawnTimer > particleSystem.spawnDurationInterval) {
		float lifeTime = particleSystem.minLifeTime + (particleSystem.maxLifeTime - particleSystem.minLifeTime) * (float)rand() / RAND_MAX;
		AddParticleToSystem(particleSystem, lifeTime);
		particleSystem.spawnTimer -= particleSystem.spawnDurationInterval;
		it = particleSystem.particleList.begin();
		while (it != particleSystem.particleList.end()) {
			std::cout << "enter ";
			it->elapsedTime += elapsedDeltaTime;
			if (it->elapsedTime > it->lifeTime) {
				it = particleSystem.particleList.erase(it);
				continue;
			}
			it++;
		}
	}
}

void ClearParticleSystem(ParticleSystem& particleSystem) {
	particleSystem.spawnTimer = 0;
	particleSystem.particleList.clear();
}

