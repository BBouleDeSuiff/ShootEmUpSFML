#include "Object.h"

Object::Object(Vector2f _position, Vector2f _scale, float _angle, float _speed){
	isDead = false;
	position = _position;
	scale = _scale;
	angle = _angle;
	speed = _speed;
	collider = SphereCollider(position, scale.x);
}
Object::Object(Vector2f _position, Vector2f _scale) {
	isDead = false;
	position = _position;
	scale = _scale;
	angle = 0;
	speed = 0;
	collider = SphereCollider(position, scale.x);
}

void Object::Draw(RenderWindow& window)
{
}

void Object::Update(float time)
{
}
