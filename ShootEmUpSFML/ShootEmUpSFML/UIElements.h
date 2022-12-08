#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<cmath>
#include "Player.h"
using namespace sf;


class UIElements
{
    private:
        // Source Variables //
        Player* playerOne;
        Player* playerTwo;
        int* score;

        // UI variables//
        Font font;

        Text life1;
        Text life2;
        CircleShape icone1;
        CircleShape icone2;

        Text scoreText;

    public:
        UIElements(Player* _playerOne, Player* _playerTwo, int* _score);

        void Update();
        void Draw(RenderWindow& window);
};
