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
    /*bool badKey = true;
    while (badKey)
    {
        badKey = false;
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            break;
        case KEY_DOWN:
            break;
        case KEY_RIGHT:
            break;
        case KEY_LEFT:
            break;
        default:
            badKey = true;
            break;
        }
    }*/

    bool game = true;
    string x;
    Grid* oGrid = new Grid();
    while (game = true)
    {
        oGrid->RandomTile();
        oGrid->Affichage();
        cout << "direction: droite, gauche, haut, bas" << endl;
        cin >> x;
        oGrid->Tileplay(x);
        if (oGrid->Win() == true) {
            game = false;
            cout << "you won !";
            break;
        }
        else if (oGrid->Loose() == true) {
            game = false;
            cout << "you lost !";
            break;
        }
    }
    
    delete oGrid;
}
