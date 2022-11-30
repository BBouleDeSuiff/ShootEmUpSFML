#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Object
{
    public:
        bool isDead;

        Vector2f position;
        Vector2f scale;
        Vector2f direction;
        float angle;
        float speed;
        //SphereCollider collider;

        virtual void Update(float time);

        Object(Vector2f _position, Vector2f _scale, Vector2f _direction, float _angle, float _speed)
        {
            isDead = false;
            position = _position;
            scale = _scale;
            direction = _direction;
            angle = _angle;
            speed = _speed;
        }
};

