#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "Grid.h"
#include "Case.h"
using namespace std;



int main()
{
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
    }
    
    delete oGrid;
}
