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
Role : trouve un nombre al�atoire entre le min et le max
Entr�e : 2 entiers (min et max)
Sortie : 1 entier (nombre al�atoire)
*******************************************/
int trouverAleatoire(int min, int max);

/************************************
Entr�e : Integer valeur min et max
Sortie : bool�an
R�le : Valide une saisie dans les bornes et sans texte
**************************************/
bool verifInt(int a, int min, int max);

/************************************
Entr�e : Integer nombre de lanc�, valeur min et max
Sortie : vecteur
R�le : Renvoie une s�quence de lancer de d�
**************************************/
vector<int> diceRoll(int nbDeRoll, int jetMin, int jetMax);
/************************************
Entr�e : Integer nombre de la probabilit� de r�ussite
Sortie : boolean
R�le : Renvoit si le coup est r�ussit
**************************************/
bool succesAttaque(int prob);
/************************************
Entr�e : Integer nombre de lanc�, valeur min et max
Sortie : integer
R�le : Renvoit le co�t en mana
**************************************/
int coutMana(int nbDeRoll, int jetMin, int jetMax);

