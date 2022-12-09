#pragma once
#include "Object.h"

class Planet : public Object
{
	private:
		CircleShape planetShape;
		Texture texture;
		int rotationSpeed; //planet's animation rotation speed
	public:
		Planet(Vector2f _position, Vector2f _scale, float _rotationSpeed);

		void Update(float time);
		void AnimateAndDraw(RenderWindow& window);
};

