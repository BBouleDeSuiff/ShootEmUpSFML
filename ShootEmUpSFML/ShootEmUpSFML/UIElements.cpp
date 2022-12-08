#include "UIElements.h"

UIElements::UIElements(Player* _playerOne, Player* _playerTwo, int* _score) {
	playerOne = _playerOne;
	playerTwo = _playerTwo;
	score = _score;

 
    font.loadFromFile("retroGaming.ttf");
    life1.setFont(font);
    life2.setFont(font);
    scoreText.setFont(font);

    life1.setCharacterSize(32);
    life2.setCharacterSize(32);
    scoreText.setCharacterSize(24);

    life1.setFillColor(sf::Color::Blue);
    life2.setFillColor(sf::Color::Red);

    scoreText.setPosition(20, 50);
    life1.setPosition(40, 530);
    life2.setPosition(750, 530);
}

void UIElements::Update()
{
    if(playerOne != nullptr)
        life1.setString(std::to_string(playerOne->life));
    if (playerTwo != nullptr)
        life2.setString(std::to_string(playerTwo->life));
    scoreText.setString(std::to_string((*score)));
}

void UIElements::Draw(RenderWindow& window)
{
    window.draw(life1);
    window.draw(life2);
    window.draw(scoreText);
}