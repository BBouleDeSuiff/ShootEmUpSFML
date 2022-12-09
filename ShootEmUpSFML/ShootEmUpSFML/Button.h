#pragma once
#include "SFML/Graphics.hpp"

class Button
{
	private:
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::RectangleShape shape;
		sf::Color color;
		sf::Color colorHover;
		sf::Color textColor;
		sf::Color textColorHover;
		std::string textString;
		int charSize;
		sf::Font font;
		sf::Text text;

	public:
		bool isClicked;
		Button();
		Button(sf::Vector2f _pos, sf::Vector2f _size, sf::Color _color, sf::Color _textColor, int _charSize, std::string _text);
		void UpdateAndDraw(sf::RenderWindow &window);
};
