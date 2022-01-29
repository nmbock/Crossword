#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //rand() , malloc()
#include <time.h> //time()
#include <stdbool.h>//bool
#include"crossword.h"


int main(void){
	
	// On commence par initialiser le generateur de nombre pseudo-aleatoires.
    	srand( time( NULL ) );
	
	char GRILLE[SIZE][SIZE]; //matrice representant le mot croise
	char BOOL[SIZE][SIZE]; //matrice booleenne indiquant la presence de caracteres
	creation(GRILLE,BOOL); //creation d'une des 2 matrices
	int nb; //entier indiquenat le nombre de mots rentres par l'utilisateur
	nb_mot(&nb);
	
	//la boucle compese de nb iterations correspond a la saisie puis insertion dans la grille des nb mots successivement
	int i; //iterateur
	for (i=1;i<=nb;i++){
		char * MOT; 
		MOT = malloc(SIZE*sizeof(char)); //cration d'un pointeur sur mot ayant pour taille max la longueur du tableau
		saisie(MOT); //saisie du dit mot
		int taille_MOT; //taille du mot saisi
		taille_MOT=longueur(MOT); //on lui affecte sa valeur par la fonction longeur()
		maj(MOT ,taille_MOT); //mise en majuscule de tous les lettres du mots
		insertion(MOT,taille_MOT,GRILLE,BOOL); //insertion du mot dans la grille de mots
		//affiche(GRILLE,BOOL); //a enlever
	}
	
	affiche(GRILLE); //on affiche l'ensemble
    char sol; //reponse du [y/n]
    printf("\n\nVoulez-vous la solution [y/n]?");
    scanf("%s",&sol); //ce n'est pas un caractere simple mais potentiollement une chaine d' ou le %s
    if(sol=='y') affiche(BOOL);
    return 0;

}