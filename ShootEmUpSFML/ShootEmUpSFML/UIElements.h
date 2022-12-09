#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include "Player.h"
#include "Line.h"
using namespace sf;


class UIElements
{
    private:
        // Source Variables //
        Player* playerOne;
        Player* playerTwo;
        Line* line;
        int* score;

        // UI variables//
        Font font;

        Text life1;
        Text life2;
        sf::RectangleShape lineBar;

        Text scoreText;

    public:
        UIElements(Player* _playerOne, Player* _playerTwo, Line* _line, int* _score);

        void Update();
        void Draw(RenderWindow& window);
};
