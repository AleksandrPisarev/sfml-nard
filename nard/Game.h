#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include "Chip.h"
#include "Dice.h"
class Game
{
	sf::RenderWindow window;
	sf::Texture bgTextur;
	sf::Sprite bgSprite;
	std::vector<Chip> field[24];
	std::vector<Dice> dice;           // хранит массив кубиков
	sf::Event event;
	int activeChip = -1;              // переменная для определения какая фишка активная (какая фишка будет ходить)
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
};

