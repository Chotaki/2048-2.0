#include "Case.h"

Case::Case()
{
    valeur = 0;
}

int Case::GetValues()
{
    return valeur;
}

void Case::ChangeValue(int i) {
    valeur = i;
}