#include "Chip.h"
Chip::Chip()
{
	shape.setRadius(13);
	shape.setFillColor(sf::Color::Black);
}

void Chip::setPosition(sf::Vector2f position)
{
	shape.setPosition(position);
}

void Chip::render(sf::RenderWindow& window)
{
	window.draw(shape);
}