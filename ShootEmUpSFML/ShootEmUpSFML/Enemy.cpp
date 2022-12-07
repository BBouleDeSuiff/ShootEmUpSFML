#include "Enemy.h"

Enemy::Enemy(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& _p1, Player& _p2, Planet& _planet, Line& _line):Object(_position, _scale, _angle, _speed)
{
	playerOne = &_p1;
	playerTwo = &_p2;
	planet = &_planet;
	target = planet;
	line = &_line;
}

void Normalize(Vector2f& vector) {
	float norm = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if(norm != 0)
		vector = vector / norm;
}

void Enemy::Update(float time)
{
	//Change position here
	direction = this->position - this->target->position;
	Normalize(direction);

	this->position -= direction * time * this->speed;

	if (collider.CheckCollision(playerOne->collider))
	{
		isDead = true;
		playerOne->life--;
	}
	else if (collider.CheckCollision(playerTwo->collider))
	{
		isDead = true;
		playerTwo->life--;
	}
	else if(collider.CheckCollision(line->collider) && line->isActive)
	{
		isDead = true;
	}
	//else if(collider.CheckCollision)
}

void Enemy::Draw(RenderWindow& window) {
	this->shape.setPosition(this->position);
	this->shape.setRotation(this->angle);
	window.draw(shape);
}

Enemy::~Enemy()
{

}
