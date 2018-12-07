#ifndef PPM_QUANTI_H
#define PPM_QUANTI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ppm_reader.h"

typedef struct palette {
	PpmCouleur *Couleur;
	int Count;
} PpmPalette;


PpmPalette* ConsPalette(int count);
int PaletteIndexOf(PpmPalette* p, PpmCouleur c);
void AjouterCouleur(PpmPalette* p, PpmCouleur c);


typedef struct palette_chainee {
	PpmCouleur Couleur;
	int Count;
	struct palette_chainee *CouleurSuivante;
	struct palette_chainee *PremierElement;
} PpmPaletteChainee;

PpmPaletteChainee* ConsPcVide();
PpmPaletteChainee* ConsPc(PpmPaletteChainee* old_p, PpmCouleur c);
bool PcEstVide(PpmPaletteChainee* p);
int PcIndexOf(PpmPaletteChainee* p, PpmCouleur c);




#endif
