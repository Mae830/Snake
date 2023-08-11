#include "Apple.h"

Apple::Apple(int len, int width) {
	circle = new sf::CircleShape();
	circle->setRadius(25);
	circle->setFillColor(sf::Color(255, 0, 100, 250));
}

void Apple::SetApplePos(int len, int width) {
	sf::Vector2f pos;
	pos.x = (rand() % width) * 50;
	pos.y = (rand() % len) * 50;
	circle->setPosition(pos.x, pos.y);
}

sf::Shape* Apple::GetShape() {
	return circle;
}
