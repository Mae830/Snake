#pragma once
#include <SFML/Graphics.hpp>
class Grass
{
	sf::RectangleShape rectangle;

public:
	Grass();
	Grass(sf::Vector2f size, sf::Color color);
	void position(int x, int y);
	sf::RectangleShape draw();
};

