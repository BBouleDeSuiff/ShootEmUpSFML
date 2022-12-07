// ConteneurSTD.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "ParticleSystem.h"
using namespace std;


void Exercice1() {
	list<float> lFloat = { 5.0f, 3.5f, 0.2f, 2.0f, 1.6f, 7.8f, 5.1f };
	list<float>::iterator it = lFloat.begin();
	while (it != lFloat.end()) {
		float nbr = *it;
		nbr -= 1;
		if (nbr <= 0) {
			it = lFloat.erase(it);
			continue;
		}
		cout << nbr << " ";
		it++;
	}
	system("pause");
}

int main()
{
	//Exercice1();
	ParticleSystem particleSystem;
	AddParticleToSystem(particleSystem, 5);
	AddParticleToSystem(particleSystem, 5);
	AddParticleToSystem(particleSystem, 5);
	auto l_front = particleSystem.particleList.begin();

	//std::advance(l_front, 1);

	//std::cout << l_front->lifeTime << '\n';
	//while(particleSystem.particleList.size()>0) {
	//	UpdateParticleSystem(particleSystem, 1);
	//}
	cout << particleSystem.particleList.size();
}