#include "Enemy.h"

Enemy::Enemy(Vector2f _position, Vector2f _scale, float _angle, float _speed, Player& p1, Player& p2) : Object(_position, _scale, _angle, _speed)
{
	playerOne = &p1;
	playerTwo = &p2;
}

void Enemy::Update(float time)
{
	//Change position here

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
}