#ifndef CROSSWORD_H
#define CROSSWORD_H

extern const int SIZE;

// Fonction/prototypes...

void affiche(char TAB[SIZE][SIZE]);
void creation(char TAB[SIZE][SIZE],char BOOL[SIZE][SIZE]);
void nb_mot(int *n);
void saisie(char *MOT);
int longueur(char *MOT);
void insertion(char *MOT,int taille_MOT,char TAB[SIZE][SIZE],char BOOL[SIZE][SIZE] );
void maj(char * MOT, int tmot);

#endif // CROSSWORD_H