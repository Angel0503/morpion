#include "game-tools.h"
#include <iostream>
using namespace std;

void afficherTableau(const int NOMBRE_CASES, char tab[][3]);
// & But : Afficher le contenu d'un tableau

void jouerCoup(char tab[][3], int tourFigure, int coup);
// & But : Rajouter la figure qu'il faut à l'endroit décidé.

void rajouterCoup(char tab[][3], char figure, int colonne, int ligne, int tourFigure);
// & But : met une figure donné dans un endroit du tableau donné

bool gererCoup(const int NBR_CASES, int tabCoup[], int coupQuonVerif);
//& But : retourne si un coup a deja ete jouer ou pas

void changerValeurTab(int pos, int tab2[]);
// & But : change la valeur tab2[pos] par 0

bool vainqueur(char tab[][3]);
//& But : retourne vrai s'il y a un vainqueur

void affichageNickel(const int NOMBRE_CASES, char tabAide[][3]);
//& But : clear l'écran et affiche le tableau d'aide

int main (void) {
    int choix;
    char vide = ' ';
    const unsigned short int NB_CASES = 3;
    const unsigned short int NB_CASES_COUP = 10;
    unsigned short int tour = 1;

    char tableauAide[NB_CASES][NB_CASES] = { 
        {'7','8','9'}, 
        {'4','5','6'}, 
        {'1','2','3'}
    };

    char tableau[NB_CASES][NB_CASES] = { 
        {vide,vide,vide}, 
        {vide,vide,vide}, 
        {vide,vide,vide}
    };

    int tableauCoup[NB_CASES_COUP] = {0,1,2,3,4,5,6,7,8,9};
     
    afficherTexteEnCouleur("CHIFOUMI", bleu, true);
    cout << endl << "Le jeu se joue avec les chiffres de votre pave numerique representant la grille de jeu." << endl;
    cout << "Vous pouvez aussi utiliser les chiffre se situant au dessus des lettres du clavier." << endl;
    cout << "N'hesitez pas a activer le verouillage de la majuscule pour jouer plus facilement." << endl;
    cout << endl << "Tableau d'aide";
    afficherTableau(NB_CASES, tableauAide);



    while(true) {
        //& saisie verif du coup jouer >> choix
        do {
            cout << endl << endl << "Choisissez votre coup : ";
            cin >> choix;
        }while(choix < 1 and choix > 9);

        //& NB_CASES_COUP, tableauCoup, choix >> verif si coup possible et joue le coup puis
        //& affiche le tableau de jeu si possible
        if(gererCoup(NB_CASES_COUP, tableauCoup, choix)) {
            changerValeurTab(choix, tableauCoup);
            affichageNickel(NB_CASES, tableauAide);
            jouerCoup(tableau, tour, choix);
            afficherTableau(NB_CASES, tableau);
            tour ++;
        }
        cout << "          " << "Tour numero : " << tour << endl;
        
        if(tour > 5) {
            if(vainqueur(tableau)) {
                if((tour + 1) %2 == 0) {
                    cout << "Les croix ont gagnes";
                    break;
                }
                else {
                    cout << "Les ronds ont gagnes";
                    break;
                }
            }
        }
        if(tour == 10) {
            cout << "EGALITE";
            break;
        }
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
            //cout << tab[i][j] << " | ";
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
    if (tab[colonneTab][ligneTab] == ' ') {
        tab[colonneTab][ligneTab] = figure;
    }
    else {
        tourFigure --;
    }
}

//& Fonction gere coup
bool gererCoup(const int NBR_CASES, int tabCoup[], int coupQuonVerif) {
    bool result = false;
    for (int i = 0; i < NBR_CASES; i++) {
        if (tabCoup[i] == coupQuonVerif) {
            result = true;
            break;
        }
    }
    return result;
}

// & Procedure changer valeur tab
void changerValeurTab(int pos, int tab2[]) {
    tab2[pos] = 0;
}

bool vainqueur(char tab[][3]) {

    //* Verif horizontale
    if(tab[0][0] != ' ' and tab[0][0] == tab[0][1] and tab[0][1] == tab[0][2]) {
        return true;
    }
    else if(tab[1][0] != ' ' and tab[1][0] == tab[1][1] and tab[1][1] == tab[1][2]) {
        return true;
    }
    else if(tab[2][0] != ' ' and tab[2][0] == tab[2][1] and tab[2][1] == tab[2][2]) {
        return true;
    }
    //* Verif verticale
    else if(tab[0][0] != ' ' and tab[0][0] == tab[1][0] and tab[1][0] == tab[2][0]) {
        return true;
    }
    else if(tab[0][1] != ' ' and tab[0][1] == tab[1][1] and tab[1][1] == tab[2][1]) {
        return true;
    }
    else if(tab[0][2] != ' ' and tab[0][2] == tab[1][2] and tab[1][2] == tab[2][2]) {
        return true;
    }
    //* Verif diag gauche-droite
    else if(tab[0][0] != ' ' and tab[0][0] == tab[1][1] and tab[1][1] == tab[2][2]) {
        return true;
    }
    //* Verif diag droite-gauche
    else if(tab[0][2] != ' ' and tab[0][2] == tab[1][1] and tab[1][1] == tab[2][0]) {
        return true;
    }
    return false;
}

void affichageNickel(const int NOMBRE_CASES, char tabAide[][3]) {
    effacer();
    
    afficherTexteEnCouleur("CHIFOUMI", bleu, true);  
    cout << endl << "Tableau d'aide";
    afficherTableau(NOMBRE_CASES,tabAide);
    cout << endl << endl << "Grille de jeu";
}
