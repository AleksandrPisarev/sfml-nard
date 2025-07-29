#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Chip.h"
class Game
{
	sf::RenderWindow window;
	sf::Texture bgTextur;
	sf::Sprite bgSprite;
	std::vector<Chip> field[24];
	sf::Vector2f fieldCoord[24] = { sf::Vector2f(108.f,114.f), sf::Vector2f(153.f,114.f), sf::Vector2f(198.f,114.f), sf::Vector2f(243.f,114.f),
								    sf::Vector2f(288.f,114.f), sf::Vector2f(333.f,114.f), sf::Vector2f(439.f,114.f), sf::Vector2f(484.f,114.f),
								    sf::Vector2f(529.f,114.f), sf::Vector2f(574.f,114.f), sf::Vector2f(619.f,114.f), sf::Vector2f(664.f,114.f),
								    sf::Vector2f(108.f,663.f), sf::Vector2f(153.f,663.f), sf::Vector2f(198.f,663.f), sf::Vector2f(243.f,663.f),
								    sf::Vector2f(288.f,663.f), sf::Vector2f(333.f,663.f), sf::Vector2f(439.f,663.f), sf::Vector2f(484.f,663.f),
								    sf::Vector2f(529.f,663.f), sf::Vector2f(574.f,663.f), sf::Vector2f(619.f,663.f), sf::Vector2f(664.f,663.f) };
	sf::Event event;
public:
	Game();
	void run();
private:
	void processEvent();
	void update();
	void render();
};

