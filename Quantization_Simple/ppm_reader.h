#include <stdio.h>
#include <stdlib.h>

typedef struct reader {
	int Width;
	int Height;
	int PixelStartAddress;
	unsigned char * Buffer;
} PpmReader;

PpmReader* OpenPPM(char *fname);
void GetPPMHeaderData(PpmReader* p);
