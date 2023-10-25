#pragma once
#include "Case.h"
#include <vector>
#include <string>
using namespace std;

class Grid
{
public:
	vector<Case> grid;
	int iGridSize;

	Grid();

	void Affichage();

	void RandomTile();

	void Tileplay(string x);

	int Position(int x, int y);

};