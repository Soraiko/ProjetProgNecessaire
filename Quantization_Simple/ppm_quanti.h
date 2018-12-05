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
} PpmPalette;

PpmPalette* ConsPaletteVide();
bool PaletteEstVide(PpmPalette* p);

PpmPalette* ConsPalette(PpmPalette* old_p, PpmCouleur c);



#endif
