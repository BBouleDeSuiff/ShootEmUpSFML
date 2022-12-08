#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include "SphereCollider.h"
using namespace sf;


class Object
{
    public:
        bool isDead;

        Vector2f position;
        Vector2f scale;
        float angle;
        float speed;
        SphereCollider collider;

        virtual void Update(float time);

        Object(Vector2f _position, Vector2f _scale, float _angle, float _speed);
        Object(Vector2f _position, Vector2f _scale); // for non-moving objects
        void Normalize(Vector2f& vector);
        virtual void Draw(RenderWindow& window);
};

