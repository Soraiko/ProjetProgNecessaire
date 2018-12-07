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

int PaletteIndexOf(PpmPalette* p, PpmCouleur c)
{
    int index = -1;
    int i;
    for (i = 0; i < (p->Count); i++)
    {
        if (Equals(p->Couleur[i], c))
        {
            index = i;
            break;
        }
    }
    return index;
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

int PcIndexOf(PpmPaletteChainee* p, PpmCouleur c)
{
    int index = -1;
    if (!PcEstVide(p))
    {
        PpmPaletteChainee* passingPalette = p->PremierElement;
        int i;
        for (i=0; i < p->Count; i++)
        {
            if (Equals(c,passingPalette->Couleur))
            {
                index = i;
                break;
            }
            passingPalette = passingPalette->CouleurSuivante;
        }
    }
    return index;
}

#endif
