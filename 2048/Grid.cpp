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

void Grid::RandomTile() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, iGridSize - 1);

    uniform_int_distribution<int> distrib4(0,9);
    for (int i = 0; i < 2; i++) {
        int position = distribution(gen);
        int chance = distrib4(gen);
        if (grid[position].GetValues() == 0) {
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

void Grid::Tileplay(string x) 
{
    int temp;
    int pos;
    if (x == "droite" or x == "bas")
    {
        for (int i = 0; i < iGridSize / 4; i++)
        {
            for (int j = 0; j < iGridSize / 4; j++)
            {

                pos = (Position(i, j));
                temp = grid[pos].GetValues();

                // glisement droite
                if (x == "droite")
                {
                    if (temp != 0)
                    {
                        if (pos - 1 < i * 4)
                        {
                            cout << "out of range" << endl;
                        }
                        else {
                            if (temp == grid[pos - 1].GetValues())
                            {

                                if (pos - 1 >= 0) {
                                    grid[pos].ChangeValue(temp * 2);
                                    grid[pos - 1].ChangeValue(0);
                                }

                            }
                        }

                    }
                    else
                    {
                        if (pos - 1 < i * 4)
                        {
                            cout << "out of RANGE" << endl;
                        }
                        else
                        {
                            if (pos - 1 >= 0) {
                                if (grid[pos - 1].GetValues() != 0)
                                {
                                    grid[pos].ChangeValue(grid[pos - 1].GetValues());
                                    grid[pos - 1].ChangeValue(0);
                                }
                            }
                        }
                    }
                }
                //glissement bas
                else if (x == "bas")
                {
                    if (temp != 0)
                    {
                        if (pos - 4 < 0 )
                        {
                            cout << "out of range" << endl;
                        }
                        else {
                            if (temp == grid[pos - 4].GetValues())
                            {

                                if (pos + 4 >= 0) {
                                    grid[pos].ChangeValue(temp * 2);
                                    grid[pos - 4].ChangeValue(0);
                                }

                            }
                        }

                    }
                    else
                    {
                        if (pos - 4 < 0)
                        {
                            cout << "out of RANGE" << endl;
                        }
                        else
                        {
                            if (pos - 4 >= 0) {
                                if (grid[pos - 4].GetValues() != 0)
                                {
                                    grid[pos].ChangeValue(grid[pos - 4].GetValues());
                                    grid[pos - 4].ChangeValue(0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
            
    else if (x == "gauche" or x == "haut")
    {
        for(int k = 3;k >= 0; k--)
        {
            for(int l = 3; l>=0 ; l--)
            {
                pos = (Position(k, l));
                temp = grid[pos].GetValues();
                //glissement gauche
                if (x == "gauche")
                {
                    if (temp != 0)
                    {
                        if (pos + 1 >= (k+1)  * 4)
                        {
                            cout << "out of range2" << endl;
                        }
                        else
                        {
                            if (temp == grid[pos + 1].GetValues())
                            {
                                if (pos + 1 <= 15)
                                {
                                    grid[pos].ChangeValue(temp * 2);
                                    grid[pos + 1].ChangeValue(0);
                                }
                            }
                        }

                    }
                    else
                    {
                        if (pos + 1 >= (k+1) * 4)
                        {
                            cout << "out of RANGE2" << endl;
                        }
                        else
                        {
                            if (pos + 1 <= 15) {
                                if (grid[pos + 1].GetValues() != 0)
                                {
                                    grid[pos].ChangeValue(grid[pos + 1].GetValues());
                                    grid[pos + 1].ChangeValue(0);
                                }
                            }
                        }
                    }
                }
                else if (x == "haut")
                {
                    if (temp != 0)
                    {
                        if (pos + 4 >15)
                        {
                            cout << "out of range2" << endl;
                        }
                        else
                        {
                            if (temp == grid[pos + 4].GetValues())
                            {
                                if (pos + 4 <= 15)
                                {
                                    grid[pos].ChangeValue(temp * 2);
                                    grid[pos + 4].ChangeValue(0);
                                }
                            }
                        }

                    }
                    else
                    {
                        if (pos + 4 > 15)
                        {
                            cout << "out of RANGE2" << endl;
                        }
                        else
                        {
                            if (pos + 4 <= 15) {
                                if (grid[pos + 4].GetValues() != 0)
                                {
                                    grid[pos].ChangeValue(grid[pos + 4].GetValues());
                                    grid[pos + 4].ChangeValue(0);
                                }
                            }
                        }
                    }
                }
            }
            
        }
    }   
}
