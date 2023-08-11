#include "board.h"
#include "Grass.h"
#include <iostream>

Board::Board(int size){
	switch (size) {
	case 0:
		this->size = size;
		this->boardLength = 500;
		this->boardWidth = 500;
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


int* Board::getdimensions() {

	static int dim[2];
	if (size == 0) {
		dim[0] = 10;
		dim[1] = 10;
	}
	return dim;
}

int Board::getWidth() {
	return boardWidth;
}

int Board::getLength() {
	return boardLength;
}