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

	printf("%x", p->PixelStartAddress);
	MettrePause();
	return EXIT_SUCCESS;
}
