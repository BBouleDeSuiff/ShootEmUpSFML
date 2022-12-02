#include "Object.h"

Object::Object(Vector2f _position, Vector2f _scale, Vector2f _direction, float _angle, float _speed) {
	isDead = false;
	position = _position;
	scale = _scale;
	direction = _direction;
	angle = _angle;
	speed = _speed;
}

