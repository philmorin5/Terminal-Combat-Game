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
Guerrier::Guerrier(string nom) : Paysan(nom) { //Constructeur surcharg�
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
		
	}cout << accent("G�n�ration de la vie : ") << tVie << "=" << m_vie << endl;
}
Guerrier::~Guerrier() { //Destructeur

}
/****************************************************************************
Entr�e : objet Paysan
Sortie : Aucune
R�le : Affiche les menus des actions
*****************************************************************************/
bool Guerrier::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" faites votre choix" << endl;
	cout << accent("1. Coup de pied renvers� (2d6 d�gat,90% de r�ussite)\n2. Attaque avec hache tranchante(4d4 d�gat, 90% de r�ussite)") << endl;

	do { //s�lection de l'attaque
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
Entr�e : Aucune
Sortie : Aucune
R�le : Pr�sente les stats du personnage
*****************************************************************************/
void Guerrier::stats() const {
	cout << "Vie | " << m_vie << endl;
}
/****************************************************************************
Entr�e : Aucune
Sortie : Aucune
R�le : Pr�sente le personnage
*****************************************************************************/

void Guerrier::affichage() const { 
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un gu�rrier sanguinaire\nIl a ") << m_vie << " de vie " << endl;
}
/****************************************************************************
Entr�e : object type Paysan en r�f�rence
Sortie : Aucune
R�le : D�duit le nombre de d�gats re�us de l'attribut m_vie du personnage
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
		cout << accent("Attaque �chou�!") << endl;
		m_feed = accent("Attaque �chou�!");
	}
}

/****************************************************************************
Entr�e : object type Paysan en r�f�rence
Sortie : Aucune
R�le : D�duit le nombre de d�gats re�us de l'attribut m_vie du personnage
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

		cout << accent("Coup de pied renvers� : ") << degat << endl;
		m_feed = accent("Coup de pied renvers� : ") + to_string(degat);
	}
	else {
		cout << accent("Attaque �chou�!") << endl;
		m_feed = accent("Attaque �chou�!");
	}
}
