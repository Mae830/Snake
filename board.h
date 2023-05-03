#pragma once
#include "Grass.h"
class Board
{
	Grass smallGround[10][10];

public:
	Board(int size);
	Grass getPlot(int i, int j);
	int* getdimensions();
};