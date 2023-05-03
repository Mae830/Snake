#include "Grass.h"

Grass::Grass() {
	rectangle.setSize(sf::Vector2f(50, 50));
	rectangle.setFillColor(sf::Color(0, 255, 0, 100));
};

Grass::Grass(sf::Vector2f size, sf::Color color) {

	rectangle.setSize(size);
	rectangle.setFillColor(color);
};

void Grass::position(int x, int y) {
	rectangle.setPosition(x, y);
}

sf::RectangleShape Grass::draw() {
	return rectangle;
}