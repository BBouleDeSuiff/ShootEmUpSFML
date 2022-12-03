#include "LineCollider.h"

LineCollider::LineCollider()
{
}

LineCollider::LineCollider(sf::Vector2f& playerOne, sf::Vector2f& playerTwo)
{
	a = &playerOne;
	b = &playerTwo;
}
