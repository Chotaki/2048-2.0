#include <iostream>
#include "Grid.h"
#include "Case.h"
#include <vector>
#include <random>
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
            if (grid[Position(i,j)].GetValue() < 10) {
                cout << "|" << " " << " " << grid[Position(i, j)].GetValue() << " " << " " << "|";
            }
            else if (grid[Position(i, j)].GetValue() >= 10 and grid[Position(i, j)].GetValue() < 100) {
                cout << "|" << " " << " " << grid[Position(i, j)].GetValue() << " " << "|";
            }
            else if (grid[Position(i, j)].GetValue() >= 100 and grid[Position(i, j)].GetValue() < 1000) {
                cout << "|" << " " << grid[Position(i, j)].GetValue() << " " << "|";
            }
            else if (grid[Position(i, j)].GetValue() >= 1000) {
                cout << "|" << " " << grid[Position(i, j)].GetValue() << "|";
            }

        }

        cout << endl;

    }
}

int Grid::Position(int x, int y) {

    return (x * 4 + y);

}

void Grid::RandomTile() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, iGridSize - 1);

    uniform_int_distribution<int> distrib4(0,9);
    for (int i = 0; i < 2; i++) {
        int position = distribution(gen);
        int chance = distrib4(gen);
        if (grid[position].GetValue() == 0) {
            if (chance == 0) {
                grid[position].ChangeValue(4);
            }
            else 
            {
                grid[position].ChangeValue(2);
            }
        }
    }
    
}

void Grid::MergeTile(int x, int y) {
    grid[x].ChangeValue(grid[x].GetValue() * 2);
    grid[y].ChangeValue(0);
    grid[x].merge = true;
}

void Grid::ResetMerge()
{
    int pos;
    for (int i = 0; i < iGridSize / 4; i++)
    {
        for (int j = 0; j < iGridSize / 4; j++)
        {
            pos = (Position(i, j));
            grid[pos].merge = false;
        }
    }
}

void Grid::TilePlayRight()
{
    int temp;
    int pos;
    for (int i = 0; i < iGridSize / 4; i++)
    {
        for (int j = 0; j < iGridSize / 4; j++)
        {

        pos = (Position(i, j));
        temp = grid[pos].GetValue();

            if (temp != 0)
            {
                if (pos - 1 < i * 4) 
                {
                    pos = pos + 1;
                }
                else {
                    if (temp == grid[pos - 1].GetValue())
                    {

                        if (pos - 1 >= 0) {
                            if (grid[pos].merge == false) {
                                MergeTile(pos, pos - 1);
                            }
                        }
                    }
                }
            }
            else
            {
                if (pos - 1 < i * 4)
                {
                    pos = pos + 1;
                }
                else
                {
                    if (pos - 1 >= 0) {
                        if (grid[pos - 1].GetValue() != 0)
                        {
                            grid[pos].ChangeValue(grid[pos - 1].GetValue());
                            grid[pos - 1].ChangeValue(0);
                        }
                    }
                }
            }
        }
    }
}
void Grid::TilePlayLeft()
{
    int temp;
    int pos;
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            pos = (Position(i, j));
            temp = grid[pos].GetValue();
            if (temp != 0)
            {
                if (pos + 1 >= (i+1) * 4)
                {
                    pos = pos - 1;
                }
                else {
                    if (temp == grid[pos + 1].GetValue())
                    {
                        if (pos + 1 <= 15) {
                            if (grid[pos].merge == false) {
                                MergeTile(pos, pos + 1);
                            }
                        }
                    }
                }
            }
            else
            {
                if (pos + 1 >= (i + 1) * 4)
                {
                    pos = pos - 1;
                }
                else
                {
                    if (pos + 1 <= 15) {
                        if (grid[pos + 1].GetValue() != 0)
                        {
                            grid[pos].ChangeValue(grid[pos + 1].GetValue());
                            grid[pos + 1].ChangeValue(0);
                        }
                    }
                }
            }
        }
    }
}

void Grid::TilePlayUp()
{
    int temp;
    int pos;
    for (int i = 3; i >= 0; i--)
    {
        for (int j = 3; j >= 0; j--)
        {
            pos = (Position(i, j));
            temp = grid[pos].GetValue();
            if (temp != 0)
            {
                if (pos + 4 > 15)
                {
                    pos = pos - 1;
                }
                else {
                    if (temp == grid[pos + 4].GetValue())
                    {
                        if (pos + 4 <= 15) {
                            if (grid[pos].merge == false) {
                                MergeTile(pos, pos + 4);
                            }
                        }
                    }
                }
            }
            else
            {
                if (pos + 4 > 15)
                {
                    pos = pos - 1;
                }
                else
                {
                    if (pos + 4 <= 15) {
                        if (grid[pos + 4].GetValue() != 0)
                        {
                            grid[pos].ChangeValue(grid[pos + 4].GetValue());
                            grid[pos + 4].ChangeValue(0);
                        }
                    }
                }
            }
        }
    }
}

void Grid::TilePlayDown() 
{
    int temp;
    int pos;
    for (int i = 0; i < iGridSize / 4; i++)
    {
        for (int j = 0; j < iGridSize / 4; j++)
        {
            pos = (Position(i, j));
            temp = grid[pos].GetValue();

            if (temp != 0)
            {
                if (pos - 4 < 0)
                {
                    pos = pos + 1;
                }
                else {
                    if (temp == grid[pos - 4].GetValue())
                    {
                        if (pos - 4 >= 0) {
                            if (grid[pos].merge == false) {
                                MergeTile(pos, pos - 4);
                            }
                        }
                    }
                }
            }
            else
            {
                if (pos - 4 < 0)
                {
                    pos = pos + 1;
                }
                else
                {
                    if (pos - 4 >= 0) {
                        if (grid[pos - 4].GetValue() != 0)
                        {
                            grid[pos].ChangeValue(grid[pos - 4].GetValue());
                            grid[pos - 4].ChangeValue(0);
                        }
                    }
                }
            }
        }
    }
}




                

bool Grid::Win() {
    int val;
    int pos;
    for (int i = 0; i < iGridSize / 4; i++)
    {
        for (int j = 0; j < iGridSize / 4; j++)
        {
            pos = (Position(i, j));
            val = grid[pos].GetValue();
            if (val == 2048) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool Grid::Loose() {
    int val;
    int pos;
    for (int i = 0; i < iGridSize / 4; i++)
    {
        for (int j = 0; j < iGridSize / 4; j++)
        {
            pos = (Position(i, j));
            val = grid[pos].GetValue();
            if (val != 2048 and val != 0) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}