#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "SphereCollider.h"
using namespace sf;


class Object
{
    protected:
        float angle;
        float speed;
    public:
        Vector2f position;
        Vector2f scale;
        SphereCollider collider;
        bool isDead;

        Object(Vector2f _position, Vector2f _scale, float _angle, float _speed);
        Object(Vector2f _position, Vector2f _scale); // for non-moving objects

        virtual void Update(float time);

        void Normalize(Vector2f& vector);
        virtual void Draw(RenderWindow& window);
};

