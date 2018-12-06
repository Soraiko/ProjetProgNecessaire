#ifndef PPM_QUANTI_H
#define PPM_QUANTI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ppm_reader.h"


typedef struct palette {
	PpmCouleur Couleur;
	int Count;
	struct palette *CouleurSuivante;
	struct palette *PremierElement;
} PpmPalette;

PpmPalette* ConsPaletteVide();
PpmPalette* ConsPalette(PpmPalette* old_p, PpmCouleur c);
bool PaletteEstVide(PpmPalette* p);
bool Contains(PpmPalette* p, PpmCouleur c);




#endif
