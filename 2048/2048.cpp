#include <iostream>
#include <vector>
#include "Grid.h"
#include "Case.h"
using namespace std;



int main()
{
    Grid* oGrid = new Grid();
    oGrid->Affichage();
    oGrid->RandomTile();
    oGrid->Affichage();
    oGrid->RandomTile();
    oGrid->Affichage();
    oGrid->RandomTile();
    oGrid->Affichage();
    delete oGrid;
}
