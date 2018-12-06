#include <stdio.h>
#include <stdlib.h>
#include "ppm_reader.h"
#include "ppm_quanti.h"
#include <time.h>

void MettrePause()
{
	getchar();
}

//  "Pc" = "Palette chainee"

int main(int argc, char *argv[])
{
    printf("Ouverture du fichier \"photo_binaire.ppm\"...\n\n");
    PpmReader* r = OpenPPM("photo_binaire.ppm");

    printf("Lecture du header... \n\n");
    GetPPMHeaderData(r);

    if ( (r->Width) * (r->Height) > 0 )
    {
        printf("Image de %dx%d pixels trouvee. \n\n",r->Width,r->Height);
    }
    else
    {
        printf("Erreur: l'image n'a pas pu etre lue, ou a mal ete lue.\n\n");
        MettrePause();
        return EXIT_FAILURE;
    }

    int x,y;
    PpmPalette* palette = ConsPalette(r->Width * r->Height); /*PpmPaletteChainee* palette = ConsPcVide();*/
    PpmCouleur c;

    int msec = 0;
    clock_t before = clock();

    printf("Recuperation de la liste des couleurs. (Version palette tableau)\n\n");
    /*printf("Recuperation de la liste des couleurs. (Version palette liste chainee)\n");*/

    for (y=0; y < (r->Height); y++)
    for (x=0; x < (r->Width); x++)
    {
        c = GetPixel(r, x, y);
        if (PaletteContains(palette,c))
            continue;

        AjouterCouleur(palette, c); /*palette = ConsPc(palette, c);*/
    }

    clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    printf("Palette de %d couleurs construite en %ds et %dms.\n\n",palette->Count, msec/1000, msec%1000);

	MettrePause();
	return EXIT_SUCCESS;
}
