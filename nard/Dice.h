#pragma once
#include <SFML/Graphics.hpp>

class Dice
{
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	std::vector<sf::CircleShape> circles;
public:
	explicit Dice(int number);
	void render(sf::RenderWindow& window);
	void setPosition(int offset);
};

