#include <iostream>
#include "Grid.h"
#include "Case.h"
#include <vector>
using namespace std;



Grid::Grid()
{
    grid = vector<Case>(16);
    iGridSize = grid.size();
}

void Grid::Affichage() {
    for (int i = 0; i < iGridSize / 4; i++)
    {
        for (int j = 0; j < iGridSize / 4; j++)
        {
            if (grid[Position(i,j)].GetValues() < 10) {
                cout << "|" << " " << " " << grid[Position(i, j)].GetValues() << " " << " " << "|";
            }
            else if (grid[Position(i, j)].GetValues() >= 10 and grid[Position(i, j)].GetValues() < 100) {
                cout << "|" << " " << " " << grid[Position(i, j)].GetValues() << " " << "|";
            }
            else if (grid[Position(i, j)].GetValues() >= 100 and grid[Position(i, j)].GetValues() < 1000) {
                cout << "|" << " " << grid[Position(i, j)].GetValues() << " " << "|";
            }
            else if (grid[Position(i, j)].GetValues() >= 1000) {
                cout << "|" << " " << grid[Position(i, j)].GetValues() << "|";
            }

        }

        cout << endl;

    }
}

int Grid::Position(int x, int y) {

    return (x * 4 + y);

}
