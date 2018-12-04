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

    PpmCouleur c = GetPixel(p, 555, 370);

	printf("%d %d %d ", c.Rouge, c.Vert, c.Bleu);
	MettrePause();
	return EXIT_SUCCESS;
}
