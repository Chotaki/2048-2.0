#include <iostream>
#include <vector>
#include "Grid.h"
#include "Case.h"
using namespace std;



int main()
{
    Grid* oGrid = new Grid();
    oGrid->Affichage();
    delete oGrid;
}
