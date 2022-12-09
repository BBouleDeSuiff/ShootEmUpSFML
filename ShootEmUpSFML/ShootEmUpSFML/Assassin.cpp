#include "Assassin.h"

Assassin::Assassin(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet, Line& _line):Enemy(_position, _scale, _angle, _speed, _p1, _p2, _planet, _line)
{
	score = 30;

	shape = sf::CircleShape(1 * _scale.x, 6);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(Color::Magenta); 
	shape.setFillColor(Color::Black);
	shape.setOrigin(1 * _scale.x, 1 * _scale.x);
}

//Euclidian distance
float GetDistance(Vector2f v1, Vector2f v2) {
	return(sqrtf(pow((v1.x - v2.x),2) + pow((v1.y - v2.y), 2)));
}

void Assassin::ResetTarget() {
	float distancePlanet = GetDistance(this->position, this->planet->position);
	float distanceP1 = GetDistance(this->position, this->playerOne->position);
	float distanceP2 = GetDistance(this->position, this->playerTwo->position);
	
	this->target = this->planet;

	if (distanceP1 < distancePlanet || distanceP2 < distancePlanet) {
		if(distanceP1< distanceP2)
			this->target = this->playerOne;
		else
			this->target = this->playerTwo;
	}

}


void Assassin::Update(float time, int& score) {
	ResetTarget();
	this->Enemy::Update(time, score);
}