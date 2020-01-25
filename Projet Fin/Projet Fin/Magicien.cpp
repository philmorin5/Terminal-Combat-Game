#include <iostream>
#include <string>
#include <vector>
#include "Magicien.h"
#include "fonction.h"

using namespace std;

Magicien::Magicien() { //constructeur

}

Magicien::Magicien(Magicien &objet) { //constructeur de copie
}
Magicien::Magicien(string nom, int surcharge): Paysan(nom),m_mana(0){

}

Magicien::Magicien(string nom) : Paysan(nom), m_mana(0){ //Constructeur surchargé
	vector<int> sequenceV;
	vector<int> sequenceM;
	string tVie;
	string tMana;

	m_arme = accent("Épée courte");
	cout << endl;
	sequenceV = diceRoll(4, 1, 20);
	for (int ctr(0); ctr < sequenceV.size(); ctr++) {
		m_vie += sequenceV[ctr];
		tVie += to_string(sequenceV[ctr]);
		if (ctr < (sequenceV.size() - 1))
		tVie += "+";
		
	}
cout << accent("Génération de la vie : ") << tVie << "=" << m_vie << endl;
	

	sequenceM = diceRoll(3, 1, 20);
	for (int ctr(0); ctr < sequenceM.size(); ctr++) {
		m_mana +=sequenceM[ctr];
		tMana += to_string(sequenceM[ctr]);
		if (ctr < (sequenceM.size() - 1))
		tMana += "+";
		
	}cout << accent("Génération du mana : ") << tMana << "=" << m_mana << endl;
}

Magicien::~Magicien() { //Destructeur

}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente les stats du personnage
*****************************************************************************/
void Magicien::stats() const {
	cout << "Vie | " << m_vie << endl;
	cout << "Mana | " << m_mana << endl;
}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente le personnage
*****************************************************************************/
void Magicien::affichage() const {
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un sage magicien.\nIl a ") << m_vie << " de vie et "<<m_mana<<" de mana." << endl;
	
}
/****************************************************************************
Entrée : Objet Paysan
Sortie : Aucune
Rôle : Affiche les menus des actions
*****************************************************************************/
bool Magicien::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" faites votre choix" << endl;
	cout << accent("1. Boule de feu (2d20 dégat,1d20 mana,75% de réussite)\n2. Attaque avec épée courte(2d4 dégat, 70% de réussite)") << endl;

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
Entrée : object type Paysan en référence
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Magicien::attaqueArme(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(2, 1, 4);
	int degat(0);
	string tDegat;
	system("CLS");
	if (succesAttaque(70)) {

		for (int ctr(0); ctr < sequence.size(); ctr++) {
			degat += sequence[ctr];

		}

		cible->recevoirDegats(degat);

		cout << accent("Coup d'Épée courte: ") << degat << endl;
		m_feed = accent("Coup d'Épée courte: ") + to_string(degat);
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
void Magicien::attaqueSpecial(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(2, 1, 20);
	int degat(0);
	int mana(0);
	string tDegat;

	mana = coutMana(1, 1, 20);
	if (m_mana >= mana) {
		m_mana -= mana;
		
		system("CLS");
		if (succesAttaque(75)) {

			for (int ctr(0); ctr < sequence.size(); ctr++) {
				degat += sequence[ctr];
		
			}

			cible->recevoirDegats(degat);

			cout << accent("Lancer de boule de feu: ") << degat<< accent(" | coût en mana: ") << mana << endl;
			m_feed = "Lancer de boule de feu: " + to_string(degat);
		}
		else {
			cout << accent("Attaque échoué!") << endl;
			m_feed = accent("Attaque échoué!");
		}
	}
	else {
		cout << accent("Vous n'avez pas assé de mana") << endl;
		m_feed = accent("Attaque échoué!");
	}
}
