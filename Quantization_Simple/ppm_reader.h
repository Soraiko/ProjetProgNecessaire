#include <stdio.h>
#include <stdlib.h>

typedef struct reader {
	int Width;
	int Height;
	int PixelStartAddress;
	int BufferSize;
	unsigned char * Buffer;
} PpmReader;

PpmReader* OpenPPM(char *fname);
void GetPPMHeaderData(PpmReader* p);
