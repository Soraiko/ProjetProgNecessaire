#include <stdio.h>
#include <stdlib.h>
#include "ppm_reader.h"
#include "ppm_quanti.h"

void MettrePause()
{
	getchar();
}

int main(int argc, char *argv[])
{
    PpmReader* r = OpenPPM("photo_binaire.ppm");
    GetPPMHeaderData(r);
    int x,y;
    PpmPalette* palette = ConsPaletteVide();
    PpmCouleur c;
    for (y=0; y < (r->Height); y++)
    for (x=0; x < (r->Width); x++)
    {
        c = GetPixel(r, x, y);
        //printf("R=%X G=%X B=%X \n", c.Rouge, c.Vert, c.Bleu);

        if (Contains(palette,c))
            continue;
        palette = ConsPalette(palette, c);
    }

    printf("%d\n", palette->Count);
    printf("DONE");
	MettrePause();
	return EXIT_SUCCESS;
}
