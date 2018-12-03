#include <stdio.h>
#include <stdlib.h>
#include "ppm_reader.h"



PpmReader* OpenPPM(char *fname)
{
    /* Cette méthode sert à copier les octets du fichier d'emplacement fname dans le Buffer de la structure PpmReader */
    PpmReader* newPPM;

	FILE *f = fopen(fname,"rb"); /* On ouvre le fichier ppm */
	fseek(f, 0L, SEEK_END); /* On se rend dà la fin du fichier pour connaitre sa taille */
	int taille_fichier = ftell(f); /* On demande la position du curseur de lecture du fichier */
	rewind(f); /* On revient au début pour lire au bon endroit (Au début...) */

	newPPM = malloc(sizeof(PpmReader) + sizeof(unsigned char *) * taille_fichier); /* On alloue les octets pour la structure PpmReader */
	newPPM->Buffer = malloc(sizeof(unsigned char *) * taille_fichier); /* On alloue les octets pour Buffer */
	fread(newPPM->Buffer, sizeof(unsigned char *), taille_fichier, f); /* C'est ici que les octets sont copiés dans Buffer */

	fclose(f); /* On ferme le fichier pour libérer le handle. */
	return newPPM;
}

void GetPPMHeaderData(PpmReader* p)
{
    /* Cette méthode sert à parcourir les premiers octets du PPM (Stockés dans le Buffer) pour acquérir la largeur, hauteur et l'adresse du premier pixel de l'image dans le fichier. */
    /* Voir le README.txt !! */
}
