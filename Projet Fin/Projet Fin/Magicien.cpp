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

Magicien::Magicien(string nom) : Paysan(nom), m_mana(0){ //Constructeur surcharg�
	vector<int> sequenceV;
	vector<int> sequenceM;
	string tVie;
	string tMana;

	m_arme = accent("�p�e courte");
	cout << endl;
	sequenceV = diceRoll(4, 1, 20);
	for (int ctr(0); ctr < sequenceV.size(); ctr++) {
		m_vie += sequenceV[ctr];
		tVie += to_string(sequenceV[ctr]);
		if (ctr < (sequenceV.size() - 1))
		tVie += "+";
		
	}
cout << accent("G�n�ration de la vie : ") << tVie << "=" << m_vie << endl;
	

	sequenceM = diceRoll(3, 1, 20);
	for (int ctr(0); ctr < sequenceM.size(); ctr++) {
		m_mana +=sequenceM[ctr];
		tMana += to_string(sequenceM[ctr]);
		if (ctr < (sequenceM.size() - 1))
		tMana += "+";
		
	}cout << accent("G�n�ration du mana : ") << tMana << "=" << m_mana << endl;
}

Magicien::~Magicien() { //Destructeur

}
/****************************************************************************
Entr�e : Aucune
Sortie : Aucune
R�le : Pr�sente les stats du personnage
*****************************************************************************/
void Magicien::stats() const {
	cout << "Vie | " << m_vie << endl;
	cout << "Mana | " << m_mana << endl;
}
/****************************************************************************
Entr�e : Aucune
Sortie : Aucune
R�le : Pr�sente le personnage
*****************************************************************************/
void Magicien::affichage() const {
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un sage magicien.\nIl a ") << m_vie << " de vie et "<<m_mana<<" de mana." << endl;
	
}
/****************************************************************************
Entr�e : Objet Paysan
Sortie : Aucune
R�le : Affiche les menus des actions
*****************************************************************************/
bool Magicien::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" faites votre choix" << endl;
	cout << accent("1. Boule de feu (2d20 d�gat,1d20 mana,75% de r�ussite)\n2. Attaque avec �p�e courte(2d4 d�gat, 70% de r�ussite)") << endl;

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
Entr�e : object type Paysan en r�f�rence
Sortie : Aucune
R�le : D�duit le nombre de d�gats re�us de l'attribut m_vie du personnage
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

		cout << accent("Coup d'�p�e courte: ") << degat << endl;
		m_feed = accent("Coup d'�p�e courte: ") + to_string(degat);
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

			cout << accent("Lancer de boule de feu: ") << degat<< accent(" | co�t en mana: ") << mana << endl;
			m_feed = "Lancer de boule de feu: " + to_string(degat);
		}
		else {
			cout << accent("Attaque �chou�!") << endl;
			m_feed = accent("Attaque �chou�!");
		}
	}
	else {
		cout << accent("Vous n'avez pas ass� de mana") << endl;
		m_feed = accent("Attaque �chou�!");
	}
}
