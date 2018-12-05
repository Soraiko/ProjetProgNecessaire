#ifndef PPM_READER_H
#define PPM_READER_H

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
} PpmCouleur;

PpmReader* OpenPPM(char *fname);
void GetPPMHeaderData(PpmReader* p);

PpmCouleur GetPixel(PpmReader* ppm, int x, int y);
PpmCouleur ConsCouleur(unsigned char r,unsigned char g, unsigned char b);

#endif
