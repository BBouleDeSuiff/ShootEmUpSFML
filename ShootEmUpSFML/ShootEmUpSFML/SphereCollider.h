#pragma once
#include <SFML/Graphics.hpp>
#include "LineCollider.h"
#include <cmath>

class SphereCollider
{
public:
	sf::Vector2f* position;
	float radius;
	SphereCollider();
	SphereCollider(sf::Vector2f& pos, float rad);
	bool CheckCollision(SphereCollider collider);
	bool CheckCollision(sf::Vector2f point);
	bool CheckCollision(LineCollider collider);
};
