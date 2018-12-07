#include <stdio.h>
#include <stdlib.h>
#include "ppm_reader.h"
#include "ppm_quanti.h"

void MettrePause()
{
	getchar();
}

//  "Pc" = "Palette chainee"

int main(int argc, char *argv[])
{
    printf("Ouverture du fichier \"photo_binaire.ppm\"...\n\n");
    PpmReader* r = OpenPPM("photo_binaire.ppm");

    printf("Lecture du header... \n\n");
    GetPPMHeaderData(r);

    int nombrePixels = (r->Width) * (r->Height);

    if ( (r->Width) * (r->Height) > 0 )
    {
        printf("Image de %dx%d pixels trouvee. \n\n",r->Width,r->Height);
    }
    else
    {
        printf("Erreur: l'image n'a pas pu etre lue, ou a mal ete lue.\n\n");
        MettrePause();
        return EXIT_FAILURE;
    }

    int i,j,x,y;
    PpmPalette* palette = ConsPalette(nombrePixels); /*PpmPaletteChainee* palette = ConsPcVide();*/
    int indices[nombrePixels]; /* Indices Non Indexés */

    PpmCouleur c;

    printf("Recuperation de la liste des couleurs... (Version palette tableau)\n\n");
    /*printf("Recuperation de la liste des couleurs. (Version palette liste chainee)\n");*/

	FILE *f = fopen("image.ppm","w");

	char str[] = "P3\n#Créé par Quantization_Simple\n0000 0000\n255\n";
	str[33] = ((r->Width) / 1000)+0x30;
	str[34] = ((r->Width%1000) / 100)+0x30;
	str[35] = ((r->Width%100) / 10)+0x30;
	str[36] = (r->Width%10)+0x30;

	str[38] = ((r->Height) / 1000)+0x30;
	str[39] = ((r->Height%1000) / 100)+0x30;
	str[40] = ((r->Height%100) / 10)+0x30;
	str[41] = (r->Height%10)+0x30;

    fwrite(str , 1 , sizeof(str)-1 , f);


    for (y=0; y < (r->Height); y++)
    for (x=0; x < (r->Width); x++)
    {
        c = GetPixel(r, x, y);
        c.Rouge = (c.Rouge / 64)*64;
        c.Bleu = (c.Bleu / 64)*64;
        c.Vert = (c.Vert / 64)*64;
        char str2[] = "000 000 000\n";
        str2[0] = ((c.Rouge%1000)/100) + 0x30;
        str2[1] = ((c.Rouge%100)/10) + 0x30;
        str2[2] = ((c.Rouge%10)) + 0x30;

        str2[4] = ((c.Vert%1000)/100) + 0x30;
        str2[5] = ((c.Vert%100)/10) + 0x30;
        str2[6] = ((c.Vert%10)) + 0x30;

        str2[8] = ((c.Bleu%1000)/100) + 0x30;
        str2[9] = ((c.Bleu%100)/10) + 0x30;
        str2[10] = ((c.Bleu%10)) + 0x30;

        fwrite(str2 , 1 , sizeof(str2)-1 , f);

        int index = PaletteIndexOf(palette,c);
        if (index>-1)       /* Je procède de cette façon car théoriquement, "Si contiens" */
        {                   /* est plus rapide que "ne contient pas" */
            indices[(r->Width * y) + x] = index;
            continue;
        }

        AjouterCouleur(palette, c); /*palette = ConsPc(palette, c);*/
    }

    fclose(f);

    printf("Palette de %d couleurs construite.\n\n",palette->Count);
    printf("Indexation sans perte initiale de %d pixels conservee.\n\n", sizeof(indices)/sizeof(indices[0]));

    //255/3 = 85 valeurs par canal de couleur
    int indicesRouges[nombrePixels];
    int indicesVert[nombrePixels];
    int indicesBleu[nombrePixels];


    /* Nous avons maintenant 256 couleurs. Mais il faut construire un nouveau tableau car les mêmes se répètent plusieurs fois */

    printf("fini");
	MettrePause();
	return EXIT_SUCCESS;
}
