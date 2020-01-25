#pragma once
#include <string>
#include <vector>
#include "Paysan.h"
#include "Guerrier.h"
#include "Pretre.h"
#include "Magicien.h"
#include "Illusionniste.h"





using namespace std;

string accent(char tab[]);

/*****************************************
Role : trouve un nombre aléatoire entre le min et le max
Entrée : 2 entiers (min et max)
Sortie : 1 entier (nombre aléatoire)
*******************************************/
int trouverAleatoire(int min, int max);

/************************************
Entrée : Integer valeur min et max
Sortie : booléan
Rôle : Valide une saisie dans les bornes et sans texte
**************************************/
bool verifInt(int a, int min, int max);

/************************************
Entrée : Integer nombre de lancé, valeur min et max
Sortie : vecteur
Rôle : Renvoie une séquence de lancer de dé
**************************************/
vector<int> diceRoll(int nbDeRoll, int jetMin, int jetMax);
/************************************
Entrée : Integer nombre de la probabilité de réussite
Sortie : boolean
Rôle : Renvoit si le coup est réussit
**************************************/
bool succesAttaque(int prob);
/************************************
Entrée : Integer nombre de lancé, valeur min et max
Sortie : integer
Rôle : Renvoit le coût en mana
**************************************/
int coutMana(int nbDeRoll, int jetMin, int jetMax);

