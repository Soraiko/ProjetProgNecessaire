Le format PPM fait partie des quelques formats d'image initiés par NetPBM.
Comme beacoup de formats libres, il s'écrit de deux façons:
	-En ASCII
	-En binaire
	
Mon programme concernera la version binaire de header "P6"
(Image brute RGB sans canal alpha)



Les informations de pixels étant brutes, le header lui reste en ASCII.

*******Explication de la fonction GetPPMHeaderData********
Cette fonction s'appuie sur le fait qu'il n'y a que trois entier (Sous forme ASCII) dans le header du fichier PPM, et qu'ils sont dans l'ordre:
	-LA LARGEUR
	-LA HAUTEUR
	-LA VALEUR MAX DES CANAUX DE COULEUR (Par défaut 255, mais mon programme ignore complètement cette valeur.)

Le programme lira le header de cette façon:
	-Tous les caractères de controle (Code ASCII <= 0x20) l'espace inclus, seront considérés comme des délimiteurs.
	-Le premier entier lu (Chaîne délimitée et ne contenenant que des chiffres) représente la largeur de l'image
	-Le second entier lu (Chaîne délimitée et ne contenenant que des chiffres) représente la hauteur de l'image
	-Le troisième entier lu (Chaîne délimitée et ne contenenant que des chiffres) représente le nombre maximal d'un canal de couleur (255) et sera ignoré.
	-Tout octet suivant directement un délimiteur après que le troisième entier à lire ai été passé, représentera le canal rouge du premier pixel. On se trouve donc à l'adresse du premier pixel.
	
--> Le but d'avoir l'addresse du premier pixel sert à obtenir la position directe d'un pixel dans le Buffer avec la fonction "fonction".