#include "SphereCollider.h"

SphereCollider::SphereCollider()
{
}

SphereCollider::SphereCollider(sf::Vector2f& pos, float rad)
{
	position = &pos;
	radius = rad;
}

bool SphereCollider::CheckCollision(SphereCollider collider)
{
	return sqrtf(powf(collider.position->x - position->x, 2.0f) + powf(collider.position->y - position->y, 2.0f)) <= collider.radius + radius;
}

bool SphereCollider::CheckCollision(sf::Vector2f point)
{
	return sqrtf(powf(point.x - position->x, 2.0f) + powf(point.y - position->y, 2.0f)) <= radius;
}

bool SphereCollider::CheckCollision(LineCollider collider)
{
	if (CheckCollision(*collider.a) || CheckCollision(*collider.b))
	{
		return true;
	}
	else
	{
		float lineLength = sqrtf(powf(collider.a->x - collider.b->x, 2.0f) + powf(collider.a->y - collider.b->y, 2.0f));
		float dot = (((position->x - collider.a->x) * (collider.b->x - collider.a->x)) + ((position->y - collider.a->y) * (collider.b->y - collider.a->y)) ) / pow(lineLength, 2);
		sf::Vector2f closest = sf::Vector2f(collider.a->x + (dot * (collider.b->x - collider.a->x)), collider.a->y + (dot * (collider.b->y - collider.a->y)));
		
		
		if (!CheckCollision(closest))
		{
			return false;
		}
		else if(sqrtf(powf(collider.a->x - closest.x, 2.0f) + powf(collider.a->y - closest.y, 2.0f)) + sqrtf(powf(collider.b->x - closest.x, 2.0f) + powf(collider.b->y - closest.y, 2.0f)) == sqrtf(powf(collider.a->x - collider.b->x, 2.0f) + powf(collider.a->y - collider.b->y, 2.0f)))
		{
			return true;
		}
	}
}