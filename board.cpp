#include "board.h"
#include "Grass.h"
#include <iostream>

Board::Board(int size){
	switch (size) {
	case 0:
		for (int i = 0; i < 10; i++) {
			int xposition = 0;
			int yposition = i * 50;
			for (int j = 0; j < 10; j++) {
				xposition = j * 50;
				if ((i + j) % 2 == 0) {
					smallGround[i][j] = Grass(sf::Vector2f(50, 50), sf::Color(0, 255, 0, 200));
				}
				else {
					smallGround[i][j] = Grass(sf::Vector2f(50, 50), sf::Color(0, 255, 0, 100));
				}
				smallGround[i][j].position(xposition, yposition);
			}
		}
		break;
	default:
		std::cout << "error";
	}
}

Grass Board::getPlot(int i, int j) {
	return smallGround[i][j];
}

//Need to refractor this
int* Board::getdimensions() {
	static int dim[2] = { 10, 10 };
	return dim;
}