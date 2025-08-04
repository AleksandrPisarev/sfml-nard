#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include<vector>
#include "Chip.h"
class Game
{
	sf::RenderWindow window;
	sf::Texture bgTextur;
	sf::Sprite bgSprite;
	std::vector<Chip> field[24];
	sf::Event event;
	int activeChip = -1;              // ���������� ��� ����������� ����� ����� �������� (����� ����� ����� ������)
public:
	Game();
	void run();
private:
	void processEvent();
	void update();
	void render();
	void startPosition();
	void movePlayer();                // ������� ���� ������
};

