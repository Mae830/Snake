#pragma once
#include "Grass.h"
class Board
{
	Grass smallGround[10][10];
	int size;
	int boardWidth;
	int boardLength;

public:
	Board(int size);
	Grass getPlot(int i, int j);
	int* getdimensions();
	int getWidth();
	int getLength();
};