#pragma once
#include "LineCollider.h"
class Line
{
public :
	Line(sf::Vector2f& playerOne, sf::Vector2f& playerTwo);
	void Update();
private:
	bool isActive;
	LineCollider collider;
};