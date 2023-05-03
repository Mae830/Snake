#pragma once
#include <SFML/Graphics.hpp>

class Apple
{
	sf::CircleShape* circle;
public:
	Apple(int len, int width);
	sf::Shape* GetShape();
	void SetApplePos(int len, int width);
};

