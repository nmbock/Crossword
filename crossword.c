#include <stdio.h> //printf(), scanf()
#include <stdlib.h> //rand() , malloc()
#include <time.h> //time()
#include <stdbool.h>//bool
#include"crossword.h"


/*------------------------------------------------------------------------------------------*/
// ce module a pour but d'afficher une matrice dans un terminal
void affiche(char TAB[SIZE][SIZE]){
	int i,j;//iterateurs i pour les lignes et j pour les colonnes
	for (i=0;i<SIZE;i++){
		printf("\n");
		for (j=0;j<SIZE;j++){
			printf(" %c ",TAB[i][j]);
			}
		}
	
}

/*-------------------------------------------------------------------------------------------*/
// ce module a pour but de faire la saisie d'un mot rentre par un utilisateur
void saisie(char *MOT){
	printf("Veuillez rentrer un mot \n");
	scanf("%s",MOT);
}

/*-------------------------------------------------------------------------------------------*/
// ce module a pour but de calculer la longueur du mot saisie
int longueur(char*MOT){
	int i=0;//iterateur
	while(MOT[i]!='\0'){
		i=i+1;
		}
	return i;
}

/*------------------------------------------------------------------------------------------*/
/*
Ce module s'occupe de faire l'insertion d'un mot dans la matrice TAB
Il fait attention a ce que 2 mots ne s'emmelent pas grace a la matrice BOOL
Un mot peut etre insere de 4 facons: horizontal, vertical, et les deux diagonales
Le choix de la facon est fait de maniere aleatoire grace a la focntion rand()%4
le switch permet de traiter les 4 differentes possibilites
*/
void insertion(char *MOT, int tmot ,char TAB[SIZE][SIZE],char BOOL[SIZE][SIZE]){
	int sens = rand()%4; //0=VERTICAL , 1=HORIZONTAL , 2=DIAGONAL GAUCHE , 3=DIAGONAL DROITE
	int ldeb_mot; //ligne du premier caractere du mot
	int cdeb_mot; //colonne du premier caractere du mot
	int i;//iterateur du bool
	int j;//iterateur de BOOL
	bool ok;//devient true quend on a pu caser un mot sans soucis
	
	ok = false;
	switch (sens){
		case 0: //insertion verticale
			while(ok!=true){
			ok = true; 
			ldeb_mot = rand()%(SIZE-tmot);//ce modulo pour pouvoir caser le mot en entier
			cdeb_mot = rand()%SIZE;//marche avec n'importe quelle colonne
			for (i=0;i<=tmot-1;i++){
				if(BOOL[ldeb_mot+i][cdeb_mot] == '1') {
					ok = false;
				}
			}
			if (ok == true){
				for (j=0;j<=tmot-1;j++){
						TAB[ldeb_mot+j][cdeb_mot] = MOT[j];
						BOOL[ldeb_mot+j][cdeb_mot] = '1';
				}
			}
			}
			break;
		
		case 1: //insertion horizontale
			while(ok!=true){
			ok = true;
			cdeb_mot = rand()%(SIZE-tmot);
			ldeb_mot = rand()%SIZE;
			for (i=0;i<=tmot-1;i++){
				if(BOOL[ldeb_mot][cdeb_mot+i] == '1') 
				ok = false;
			}
			if (ok == true){
				for (j=0;j<=tmot-1;j++){
					TAB[ldeb_mot][cdeb_mot+j] = MOT[j];
					BOOL[ldeb_mot][cdeb_mot+j] = '1';
					}
			}
			}
			break;
		
		case 2: //insertion diagonale du bas gauche a en haut a droite
			while(ok!=true){
			ok = true;
			cdeb_mot = rand()%(SIZE-tmot);
			ldeb_mot = rand()%(SIZE-tmot);
			for(i=0;i<=tmot-1;i++){
				if(BOOL[ldeb_mot+i][cdeb_mot+i] == '1') {
					ok = false;
				}
			}
			if (ok == true){
				for(j=0;j<=tmot-1;j++){
					TAB[ldeb_mot+j][cdeb_mot+j]=MOT[j];
					BOOL[ldeb_mot+j][cdeb_mot+j] = '1';
					}
			
			}
			}
			break;
			
		case 3: //insertion diagonale du haut droit au bas gauche
			while(ok!=true){ 
			ok = true;
			cdeb_mot = tmot+rand()%(SIZE-tmot);
			ldeb_mot = rand()%(SIZE-tmot);
			for(i=0;i<=tmot-1;i++){
				if(BOOL[ldeb_mot+i][cdeb_mot-i] == '1') {
				ok = false;
				}
			}
			if(ok == true){
				for(j=0;j<=tmot-1;j++){
						TAB[ldeb_mot+j][cdeb_mot-j]=MOT[j];	
						BOOL[ldeb_mot+j][cdeb_mot-j] = '1';
					}
			}
			
			}
			break;
	}
	}

/*------------------------------------------------------------------------------------------*/
void creation(char TAB[SIZE][SIZE],char BOOL[SIZE][SIZE]){
	int i,j;//iterateurs pour parcourir le tableau
	
	for (i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			TAB[i][j] = (char) (65+(rand()%24)); //lettre aleatoire en majuscule
			BOOL[i][j] = '0';
			}
		}
}

/*------------------------------------------------------------------------------------------*/
void nb_mot(int *n){
	printf("Veuillez rentrer le nombre de mots que vous souhaitez \n");
	scanf("%d",n); //saisie en memoire de l'entier
}

/*------------------------------------------------------------------------------------------*/
void maj(char * MOT, int tmot){
	int i;	
	for (i=0;i<=tmot-1;i++){
		if (((int)MOT[i]<=122)&&((int)MOT[i]>=97)) //on regarde si le caractere est minuscule sur la table ascii
			MOT[i] = ((char)((int)MOT[i]-32));
			//printf("%c" ,MOT[i]);
	}
}
/*------------------------------------------------------------------------------------------*/