#include <stdio.h>
#include <stdlib.h>
#include "ppm_reader.h"

void MettrePause()
{
	getchar();
}

int main(int argc, char *argv[])
{
    PpmReader* p = OpenPPM("photo_binaire.ppm");

    GetPPMHeaderData(p);
    Couleur c = GetPixel(p, 228, 138);

	printf("%d %d %d ", c.Rouge, c.Vert, c.Bleu);
	MettrePause();
	return EXIT_SUCCESS;
}
