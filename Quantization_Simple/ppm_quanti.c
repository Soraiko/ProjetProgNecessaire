#ifndef PPM_QUANTI_C
#define PPM_QUANTI_C

#include <stdio.h>
#include <stdlib.h>
#include "ppm_quanti.h"
#include <stdbool.h>

PpmPalette* ConsPaletteVide()
{
    return NULL;
}

bool PaletteEstVide(PpmPalette* p)
{
    return p == NULL;
}

PpmPalette* ConsPalette(PpmPalette* old_p, PpmCouleur c)
{
    PpmPalette* p = malloc(sizeof(PpmCouleur)+ sizeof(PpmPalette));
    p->Couleur = c;
    if (PaletteEstVide(old_p))
    {
        p->Count = 1;
    }
    else
    {
        old_p->CouleurSuivante = p;
        old_p->Count = old_p->Count + 1;
        p->Count = old_p->Count;
    }
    return p;
}


#endif
