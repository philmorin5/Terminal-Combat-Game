#include <iostream>
#include <string>
#include <vector>
#include "Guerrier.h"
#include "fonction.h"

using namespace std;

Guerrier::Guerrier() { //constructeur
	
}
Guerrier::Guerrier(Guerrier &objet) { //constructeur de copie

}
Guerrier::Guerrier(string nom) : Paysan(nom) { //Constructeur surchargé
	vector<int> sequence;
	string tVie;
	m_arme = accent("Marteau");
	cout << endl;
	sequence = diceRoll(7, 1, 20);
	for (int ctr(0); ctr < sequence.size(); ctr++) {
		m_vie += sequence[ctr];
		tVie += to_string(sequence[ctr]);
		if (ctr < (sequence.size() - 1))
		tVie += "+";
		
	}cout << accent("Génération de la vie : ") << tVie << "=" << m_vie << endl;
}
Guerrier::~Guerrier() { //Destructeur

}
/****************************************************************************
Entrée : objet Paysan
Sortie : Aucune
Rôle : Affiche les menus des actions
*****************************************************************************/
bool Guerrier::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" faites votre choix" << endl;
	cout << accent("1. Coup de pied renversé (2d6 dégat,90% de réussite)\n2. Attaque avec hache tranchante(4d4 dégat, 90% de réussite)") << endl;

	do { //sélection de l'attaque
		cin >> cmd;
	} while (!verifInt(cmd, 1, 2));

	switch (cmd) {

	case 1:
		attaqueSpecial(cible);
		break;

	case 2:
		attaqueArme(cible);
		break;

	}
	return false;

}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente les stats du personnage
*****************************************************************************/
void Guerrier::stats() const {
	cout << "Vie | " << m_vie << endl;
}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente le personnage
*****************************************************************************/

void Guerrier::affichage() const { 
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un guérrier sanguinaire\nIl a ") << m_vie << " de vie " << endl;
}
/****************************************************************************
Entrée : object type Paysan en référence
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Guerrier::attaqueArme(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(4, 1, 4);
	int degat(0);
	string tDegat;
	system("CLS");
	if (succesAttaque(90)) {

		for (int ctr(0); ctr < sequence.size(); ctr++) {
			degat += sequence[ctr];
		
		}

		cible->recevoirDegats(degat);

		cout << accent("Coup d'hache tranchante : ") << degat << endl;
		m_feed = "Coup d'hache tranchante : "+ to_string(degat);
	}
	else {
		cout << accent("Attaque échoué!") << endl;
		m_feed = accent("Attaque échoué!");
	}
}

/****************************************************************************
Entrée : object type Paysan en référence
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Guerrier::attaqueSpecial(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(2, 1, 6);
	int degat(0);
	string tDegat;
	system("CLS");
	if (succesAttaque(90)) {

		for (int ctr(0); ctr < sequence.size(); ctr++) {
			degat += sequence[ctr];
			tDegat += to_string(sequence[ctr]);
			
			if (ctr < (sequence.size() - 1))
				tDegat += "+";
		}

		cible->recevoirDegats(degat);

		cout << accent("Coup de pied renversé : ") << degat << endl;
		m_feed = accent("Coup de pied renversé : ") + to_string(degat);
	}
	else {
		cout << accent("Attaque échoué!") << endl;
		m_feed = accent("Attaque échoué!");
	}
}
