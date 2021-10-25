//#include "game-tools.h"
#include <iostream>
using namespace std;

void afficherTableau(const int NOMBRE_CASES, char tab[][3]);
// & But : Afficher le contenu d'un tableau

void jouerCoup(char tab[][3], int tourFigure, int coup);
// & But : Rajouter la figure qu'il faut à l'endroit décidé.

void rajouterCoup(char tab[][3], char figure, int colonne, int ligne, int tourFigure);
// & But : met une figure donné dans un endroit du tableau donné


int main (void) {
    //bool vide = true;
    int choix;
    const unsigned short int NB_CASES = 3;
    unsigned short int tour = 1;

    char tableau[NB_CASES][NB_CASES] = { 
        {true,true,true}, 
        {true,true,true}, 
        {true,true,true}
    };
    
    while(true) {
        do {
            cout << "Choisissez votre coup : ";
            cin >> choix;
        }while(choix != 1 && choix != 2 && choix != 3 && 
               choix != 4 && choix != 5 && choix != 6 &&
               choix != 7 && choix != 8 && choix != 9);
        cout << "-------" << endl << "numero 1 :" << tour << endl << "-------" << endl;
        jouerCoup(tableau, tour, choix);
        afficherTableau(NB_CASES, tableau);
        cout << "-------" << endl << "numero 2 :" << tour << endl << "-------" << endl;
        tour ++;
        cout << "-------" << endl << "numero 3 :" << tour << endl << "-------" << endl;
    };    
    return 0;
}

//& Procedure afficher tableau
void afficherTableau(const int NOMBRE_CASES, char tab[][3]) {
    for(int i = 0; i < NOMBRE_CASES; i++) {
        cout << endl << "| ";
        for(int j = 0; j < NOMBRE_CASES; j++) {
            if (tab[i][j] == true){
                cout << " " << " | ";
            }
            else {
                cout << tab[i][j] << " | ";
            }   
        };
    }
}

//& Procedure jouer un coup
void jouerCoup(char tab[][3], int tourFigure, int coup) {
    char croix = 'X';
    char rond = 'O';
    char figureJouer;
    int colonne;
    int ligne;

    if (tourFigure % 2 == 0) {
        figureJouer = croix;
    }
    else {
        figureJouer = rond;
    }

    switch(coup) {
        case 7 :
        ligne = 0;
        colonne = 0;
        break;

        case 8 :
        ligne = 1;
        colonne = 0;
        break;

        case 9 :
        ligne = 2;
        colonne = 0;
        break;

        case 4 :
        ligne = 0;
        colonne = 1;
        break;

        case 5 :
        ligne = 1;
        colonne = 1;
        break;
        
        case 6 :
        ligne = 2;
        colonne = 1;
        break;

        case 1 :
        ligne = 0;
        colonne = 2;
        break;

        case 2 :
        ligne = 1;
        colonne = 2;
        break;
        
        case 3 :
        ligne = 2;
        colonne = 2;
        break;
    }
    rajouterCoup(tab, figureJouer, colonne, ligne, tourFigure);
}

//& Procedure rajouter un coup
void rajouterCoup(char tab[][3], char figure, int colonneTab, int ligneTab, int tourFigure) {
    if (tab[colonneTab][ligneTab] == true) {
        tab[colonneTab][ligneTab] = figure;
    }
    else {
        tourFigure --;
    }
}