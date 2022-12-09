#include "Button.h"
#include <iostream>

Button::Button(){}

Button::Button(sf::Vector2f _pos, sf::Vector2f _size, sf::Color _color, sf::Color _textColor, int _charSize, std::string _text)
{
	isClicked = false;
	font.loadFromFile("../Font.otf");
	color = _color;
	colorHover = sf::Color(_color.r + _color.r / 255 * 100, _color.g + _color.g / 255 * 100, _color.b + _color.b / 255 * 100);
	textColor = _textColor;
	textColorHover = sf::Color(_textColor.r + _textColor.r / 255 * 100, _textColor.g + _textColor.g / 255 * 100, _textColor.b + _textColor.b / 255 * 100);
	textString = _text;
	charSize = _charSize;
	pos = sf::Vector2f(_pos.x - _size.x / 2.0f, _pos.y - _size.y / 2.0f);
	size = _size;
}

void Button::UpdateAndDraw(sf::RenderWindow &window)
{
	shape.setPosition(pos);
	shape.setSize(size);
	shape.setFillColor(color);

	text.setPosition(pos);
	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(charSize);
	text.setFillColor(textColor);

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (mousePos.x < pos.x + size.x && mousePos.x > pos.x && mousePos.y < pos.y + size.y && mousePos.y > pos.y)
	{
		text.setFillColor(textColorHover);
		shape.setFillColor(colorHover);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			isClicked = true;
		}
	}
	window.draw(shape);
	window.draw(text);
}