#pragma once
#include <SFML/Graphics.hpp>
class Chip
{
	sf::CircleShape shape;
public:
	Chip();
	void setPosition(sf::Vector2f position);
	void render(sf::RenderWindow& window);
};

