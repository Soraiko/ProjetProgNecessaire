#ifndef PPM_READER_C
#define PPM_READER_C

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
    newPPM->Width = 0;
    newPPM->Height = 0;
    newPPM->PixelStartAddress = 0;
    newPPM->BufferSize = taille_fichier;

	fclose(f); /* On ferme le fichier pour libérer le handle. */
	return newPPM;
}

PpmCouleur GetPixel(PpmReader* ppm, int x, int y)
{
    PpmCouleur c;
    int position_pixel = ppm->PixelStartAddress + (ppm->Width * y * 3) + (x * 3); /* x3 car 3 couleurs par pixel */
    c.Rouge = ppm->Buffer[position_pixel];
    c.Vert = ppm->Buffer[position_pixel+1];
    c.Bleu = ppm->Buffer[position_pixel+2];
    return c;
}

PpmCouleur ConsCouleur(unsigned char r,unsigned char g, unsigned char b)
{
    PpmCouleur c;
    c.Rouge = r;
    c.Vert = g;
    c.Bleu = b;
    return c;
}

bool Equals(PpmCouleur a, PpmCouleur b)
{
    return a.Rouge == b.Rouge && a.Vert == b.Vert && a.Bleu == b.Bleu;
}

void GetPPMHeaderData(PpmReader* ppm)
{
    /* Cette méthode sert à parcourir les premiers octets du PPM (Stockés dans le Buffer) pour acquérir la largeur, hauteur et l'adresse du premier pixel de l'image dans le fichier. */
    /* Voir le README !! */
    int positionLecture = 0;
    int pos_debut_entier_a_lire = -1; /* Entier ASCII [0x30-0x39] à chercher. */
    int ascii_num_count = 0;

    while (positionLecture < ppm->BufferSize)
    {
        if (ppm->Buffer[positionLecture]<=0x20) /* Nous somme sur un délimiteur ASCII (Caractère de contrôle) */
        {
            if (pos_debut_entier_a_lire > -1 && positionLecture - pos_debut_entier_a_lire == ascii_num_count)
            {
                /* Nous somme ici si nous n'avons croisé que des ASCII numériques entre deux délimiteurs */
                int entier_a_parser = 0;
                int i;
                for (i=0;i<ascii_num_count;i++)
                {
                    float cent_diz_unite = pow(10.0,(ascii_num_count-i-1));
                    entier_a_parser = entier_a_parser + (int)(((ppm->Buffer[pos_debut_entier_a_lire + i])-0x30) * cent_diz_unite);
                }
                if (ppm->Width == 0)
                {
                    ppm->Width = entier_a_parser;
                }
                else if (ppm->Height == 0)
                {
                    ppm->Height = entier_a_parser;
                }
                else /* On ignore "entier_a_parser" cette fois-ci car il s'agit du troisième entier (Valeur max du canal de couleur) */
                {
                    ppm->PixelStartAddress = positionLecture+1; /* Le délimiteur juste après ce troisième entier est juste avant l'octet du premier pixel (Voir readme)*/
                    break; /* Ona finit de lire les information header */
                }
            }
            pos_debut_entier_a_lire = -1;
            ascii_num_count = 0;
        }
        else
        {
            if (pos_debut_entier_a_lire<0)
                pos_debut_entier_a_lire = positionLecture;

            if (ppm->Buffer[positionLecture]>=0x30 && ppm->Buffer[positionLecture]<=0x39) /* Nous somme sur un chiffre ASCII */
            {
                ascii_num_count++;
            }
        }
        positionLecture++;
    }
}

#endif
