#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <conio.h>
#include "Grid.h"
#include "Case.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
    bool game = true;
    string x;
    Grid* oGrid = new Grid();
    //oGrid->grid[0].ChangeValue(2);
    //oGrid->grid[4].ChangeValue(16);
    //oGrid->grid[8].ChangeValue(4);
    //oGrid->grid[12].ChangeValue(8);
    while (game = true)
    {
        oGrid->RandomTile();
        oGrid->ResetMerge();
        oGrid->Affichage();
        cout << endl;
        if (oGrid->Win() == true) {
            game = false;
            cout << "you won !";
            break;
        }
        if (oGrid->Loose() == true) {
            game = false;
            cout << "you lost !";
            break;
        }
        bool badKey = true;
        while (badKey)
        {
            badKey = false;
            int c = 0;
            switch ((c = _getch()))
            {
            case KEY_UP:
                oGrid->TilePlayUp();
                break;
            case KEY_DOWN:
                oGrid->TilePlayDown();
                break;
            case KEY_RIGHT:
                oGrid->TilePlayRight();
                break;
            case KEY_LEFT:
                oGrid->TilePlayLeft();
                break;
            default:
                badKey = true;
                break;
            }
        }
        
    }
    
    delete oGrid;
}
