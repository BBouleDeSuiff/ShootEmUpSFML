#include "Soldier.h"

Soldier::Soldier(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet):Enemy(_position,_scale, _angle, _speed, _p1, _p2, _planet)
{

	shape = sf::CircleShape(1 * _scale.x, 6);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(Color(255,127,0)); //Orange
	shape.setFillColor(Color::Black);
	shape.setOrigin(1 * _scale.x, 1 * _scale.x);

}


void Soldier::Update(float time) {
	Enemy::Update(time);
}