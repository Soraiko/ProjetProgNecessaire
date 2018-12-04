#include <stdio.h>
#include <stdlib.h>

typedef struct reader {
	int Width;
	int Height;
	int PixelStartAddress;
	int BufferSize;
	unsigned char * Buffer;
} PpmReader;

typedef struct couleur {
	unsigned char Rouge;
	unsigned char Vert;
	unsigned char Bleu;
} Couleur;

PpmReader* OpenPPM(char *fname);
void GetPPMHeaderData(PpmReader* p);

Couleur GetPixel(PpmReader* ppm, int x, int y);
