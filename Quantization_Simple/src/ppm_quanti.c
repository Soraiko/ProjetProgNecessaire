#ifndef PPM_QUANTI_C
#define PPM_QUANTI_C

#include <stdio.h>
#include <stdlib.h>
#include "ppm_quanti.h"
#include <stdbool.h>



PpmPalette* ConsPalette(int count)
{
    PpmPalette* p = malloc(sizeof(PpmPalette) + (sizeof(PpmCouleur) * count-1));
    p->Count = 0;
    p->Couleur = malloc(sizeof(PpmCouleur) * count);
    return p;
}

void AjouterCouleur(PpmPalette* p, PpmCouleur c)
{
    p->Couleur[p->Count] = c;
    p->Count = p->Count + 1;
}

bool PaletteContains(PpmPalette* p, PpmCouleur c)
{
    bool contains = false;
    int i;
    for (i = 0; i < (p->Count); i++)
    {
        if (Equals(p->Couleur[i], c))
        {
            contains = true;
            break;
        }
    }
    return contains;
}






PpmPaletteChainee* ConsPcVide()
{
    return NULL;
}

bool PcEstVide(PpmPaletteChainee* p)
{
    return p == NULL;
}

PpmPaletteChainee* ConsPc(PpmPaletteChainee* old_p, PpmCouleur c)
{
    PpmPaletteChainee* p = malloc(sizeof(PpmCouleur)+ sizeof(PpmPaletteChainee));
    p->Couleur = c;
    if (PcEstVide(old_p))
    {
        p->Count = 1;
        p->PremierElement = p;
        p->CouleurSuivante = ConsPcVide();
    }
    else
    {
        old_p->CouleurSuivante = p;
        old_p->Count = old_p->Count + 1;
        p->Count = old_p->Count;
        p->PremierElement = old_p->PremierElement;
    }
    return p;
}

bool PcContains(PpmPaletteChainee* p, PpmCouleur c)
{
    bool contains = false;
    if (!PcEstVide(p))
    {
        PpmPaletteChainee* passingPalette = p->PremierElement;
        int i;
        for (i=0; i < p->Count; i++)
        {
            if (Equals(c,passingPalette->Couleur))
            {
                contains = true;
                break;
            }
            passingPalette = passingPalette->CouleurSuivante;
        }
    }
    return contains;
}

#endif
