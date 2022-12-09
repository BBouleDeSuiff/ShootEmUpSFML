#include "Object.h"

Object::Object(Vector2f _position, Vector2f _scale, float _angle, float _speed) : collider(position,_scale.x) {
	isDead = false;
	position = _position;
	scale = _scale;
	angle = _angle;
	speed = _speed;
}
Object::Object(Vector2f _position, Vector2f _scale) : collider(position, _scale.x) {
	isDead = false;
	position = _position;
	scale = _scale;
	angle = 0;
	speed = 0;
}

void Object::Normalize(Vector2f& vector) {
	float norm = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (norm != 0)
		vector = vector / norm;
}

void Object::Draw(RenderWindow& window)
{
}

void Object::Update(float time)
{
}
