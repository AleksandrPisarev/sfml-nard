#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include "Chip.h"
#include "Dice.h"
class Game
{
	sf::RenderWindow window;
	sf::Texture bgTextur, buttonTextur;
	sf::Sprite bgSprite, buttonSprite;
	std::vector<Chip> field[24];
	std::vector<Dice> dice;           // хранит массив кубиков
	int activeChip = -1;              // переменная для определения какая фишка активная (какая фишка будет ходить)
	sf::Event event;
public:
	Game();
	void run();
private:
	void processEvent();
	void update();
	void render();
	void startPosition();
	void movingChips();                // функция перемещение фишек
	void rollofDice();                 // функция бросок кубиков
	void playersTurn();                // функция ход игрока
};

