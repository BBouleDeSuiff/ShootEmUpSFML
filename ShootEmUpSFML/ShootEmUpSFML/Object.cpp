#include "Object.h"

Object::Object(Vector2f _position, Vector2f _scale, float _angle, float _speed) {
	isDead = false;
	position = _position;
	scale = _scale;
	angle = _angle;
	speed = _speed;
}

