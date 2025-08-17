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
	std::vector<Dice> dice;           // ������ ������ �������
	int activeChip = -1;              // ���������� ��� ����������� ����� ����� �������� (����� ����� ����� ������)
	sf::Event event;
public:
	Game();
	void run();
private:
	void processEvent();
	void update();
	void render();
	void startPosition();
	void movingChips();                // ������� ����������� �����
	void rollofDice();                 // ������� ������ �������
	void playersTurn();                // ������� ��� ������
};

