#include "Planet.h"
Planet::Planet(Vector2f _position, Vector2f _scale, float _rotationSpeed):Object(_position, _scale){
    position = _position;
    scale = _scale;
    planetShape = sf::CircleShape(1 * _scale.x);

    rotationSpeed = _rotationSpeed;


    if (texture.loadFromFile("jupiterTexture.jpg"))
        std::cout << "Unable to load texture" << std::endl;
    else
        texture.loadFromFile("jupiterTexture.jpg");

    planetShape.setPosition(_position);
    planetShape.setTexture(&texture);
    planetShape.setOrigin(1 * _scale.x, 1 * _scale.x); //Set anchor point to planet's center
}

void Planet::Update(float time) {
    this->angle += 1 * this->rotationSpeed * time;
}

void Planet::AnimateAndDraw(RenderWindow& window) {
    this->planetShape.setRotation(this->angle);
    window.draw(planetShape);
}