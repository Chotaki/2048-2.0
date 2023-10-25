#pragma once
#include "Case.h"
#include <vector>
using namespace std;

class Grid
{
public:
	vector<Case> grid;
	int iGridSize;

	Grid();

	void Affichage();

	int Position(int x, int y);

};