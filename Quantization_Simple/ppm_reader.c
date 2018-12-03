#include <stdio.h>
#include <stdlib.h>
#include "ppm_reader.h"



PpmReader* OpenPPM(char *fname)
{
    /* Cette m�thode sert � copier les octets du fichier d'emplacement fname dans le Buffer de la structure PpmReader */
    PpmReader* newPPM;

	FILE *f = fopen(fname,"rb"); /* On ouvre le fichier ppm */
	fseek(f, 0L, SEEK_END); /* On se rend d� la fin du fichier pour connaitre sa taille */
	int taille_fichier = ftell(f); /* On demande la position du curseur de lecture du fichier */
	rewind(f); /* On revient au d�but pour lire au bon endroit (Au d�but...) */

	newPPM = malloc(sizeof(PpmReader) + sizeof(unsigned char *) * taille_fichier); /* On alloue les octets pour la structure PpmReader */
	newPPM->Buffer = malloc(sizeof(unsigned char *) * taille_fichier); /* On alloue les octets pour Buffer */
	fread(newPPM->Buffer, sizeof(unsigned char *), taille_fichier, f); /* C'est ici que les octets sont copi�s dans Buffer */

	fclose(f); /* On ferme le fichier pour lib�rer le handle. */
	return newPPM;
}

void GetPPMHeaderData(PpmReader* p)
{
    /* Cette m�thode sert � parcourir les premiers octets du PPM (Stock�s dans le Buffer) pour acqu�rir la largeur, hauteur et l'adresse du premier pixel de l'image dans le fichier. */
    /* Voir le README.txt !! */
}
