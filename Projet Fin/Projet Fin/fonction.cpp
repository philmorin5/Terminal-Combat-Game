#pragma once
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <Windows.h>
#include "fonction.h"
#include "Paysan.h"
#include "Guerrier.h"
#include "Pretre.h"
#include "Magicien.h"
#include "Illusionniste.h"
#undef max;
using namespace std;


int trouverAleatoire(int min, int max) {

	int nombre;
	nombre = (rand() % ((max - min) + 1)) + min;
	return nombre;
}

bool verifInt(int a, int min, int max) {
	bool resultat(false);

	//Vérifie si la saisie est entre min et max inclu.
	if (a >= min && a <= max && !cin.fail()) {
		resultat = true;
	}
	//Afficher un message d'échec.
	else
		cout << "Veuillez entrer une valeur entre " << min << " et " << max << " inclusivement." << endl;

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return resultat;
}

string accent(char tab[]) {
	char buffer[256];
	CharToOemA(tab, buffer);
	string str(buffer);
	return str;
}

vector<int> diceRoll(int nbDeRoll, int jetMin, int jetMax) {
	vector<int> sequence;
	for (int ctr(0); ctr < nbDeRoll; ctr++) {
		sequence.push_back(trouverAleatoire(jetMin, jetMax));
	}

	return sequence;
}

bool succesAttaque(int prob) {
	bool succes(false);

	if (trouverAleatoire(0, 100) <= prob) {
		succes = true;
	}
	return succes;
}

int coutMana(int nbDeRoll, int jetMin, int jetMax) {
	int coutMana(0);
	vector<int> sequence(diceRoll(nbDeRoll, jetMin, jetMax));

	for (int ctr(0); ctr < sequence.size(); ctr++) {
		coutMana += sequence[ctr];
	}

	return coutMana;
}



