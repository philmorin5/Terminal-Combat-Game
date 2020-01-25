#include <iostream>
#include <string>
#include <vector>
#include "Pretre.h"
#include "fonction.h"

using namespace std;

Pretre::Pretre() { //constructeur

}

Pretre::Pretre(string nom) : Paysan(nom), m_mana(0) { //Constructeur surchargé
	vector<int> sequenceV;
	vector<int> sequenceM;
	string tVie;
	string tMana;

	m_arme = accent("Marteau");
	cout << endl;
	sequenceV = diceRoll(5, 1, 20);
	for (int ctr(0); ctr < sequenceV.size(); ctr++) {
		m_vie += sequenceV[ctr];
		m_vieTot = m_vie;
		tVie += to_string(sequenceV[ctr]);
		if (ctr < (sequenceV.size() - 1))
		tVie += "+";
	
		
	}
cout << accent("Génération de la vie : ") << tVie << "=" << m_vie << endl;


	sequenceM = diceRoll(2, 1, 20);
	for (int ctr(0); ctr < sequenceM.size(); ctr++) {
		m_mana += sequenceM[ctr];
		tMana += to_string(sequenceM[ctr]);
		if (ctr < (sequenceM.size() - 1))
		tMana += "+";
	
	}cout << accent("Génération du mana : ") << tMana << "=" << m_mana << endl;
}	


Pretre::Pretre(Pretre &objet) { //constructeur de copie

}
Pretre::~Pretre() { //Destructeur

}
/****************************************************************************
Entrée : objet Paysan
Sortie : Aucune
Rôle : Affiche les menus des actions
*****************************************************************************/
bool Pretre::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" Faites votre choix" << endl;
	cout << accent("1. Attaque céleste (2d8 dégat,1d10 mana,80% de réussite)\n2. Attaque avec marteau(2d6 dégat, 75% de réussite)\n3. Sort de soin (1d10 soin, 1d8 mana, 90% de réussite)")<<endl;

	do { //sélection de l'attaque
		cin >> cmd;
	} while (!verifInt(cmd, 1, 3));

	switch (cmd) {

	case 1:
		attaqueSpecial(cible);
		break;

	case 2:
		attaqueArme(cible);
		break;

	case 3:
		soin();
		break;
	}
	return false;
}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente le personnage
*****************************************************************************/
void Pretre::affichage() const {
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un puissant prêtre.\nIl a ") << m_vie << " de vie et "<<m_mana<<" de mana." << endl;
}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente les stats du personnage
*****************************************************************************/
void Pretre::stats() const {
	cout << "Vie | " << m_vie << endl;
	cout << "Mana | " << m_mana << endl;
}

/****************************************************************************
Entrée : object type Paysan en référence
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Pretre::attaqueArme(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(2, 1, 6);
	int degat(0);
	string tDegat;
	system("CLS");
	if (succesAttaque(75)) {

		for (int ctr(0); ctr < sequence.size(); ctr++) {
			degat += sequence[ctr];
		
		}

		cible->recevoirDegats(degat);

		cout << accent("Coup de marteau: ") << degat << endl;
		m_feed = accent("Coup de marteau: ") + to_string(degat);
	}
	else
		cout << accent("Attaque échoué!") << endl;
}

/****************************************************************************
Entrée : object type Paysan en référence
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Pretre::attaqueSpecial(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(2, 1, 8);
	int degat(0);
	int mana(0);
	string tDegat;

	mana = coutMana(1, 1, 10);
	if ( m_mana>= mana) {
		m_mana -= mana;
		system("CLS");
		if (succesAttaque(80)) {

			for (int ctr(0); ctr < sequence.size(); ctr++) {
				degat += sequence[ctr];
			
			}

			cible->recevoirDegats(degat);

			cout << accent("Lance une attaque céleste: ") << degat << accent(" | coût en mana: ")<<mana << endl;
			m_feed = accent("Lance une attaque céleste: ") + to_string(degat);
		}
		else
			cout << accent("Attaque échoué!") << endl;
	}
	else
		cout << accent("Vous n'avez pas assé de mana") << endl;

}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Ajoute le nombre de soin reçu à l'attribut m_vie du personnage
*****************************************************************************/
void Pretre::soin() {
	
	int mana(0);

	vector<int> sequence(diceRoll(1, 1, 10));

	mana = coutMana(1, 1, 8);
	if (m_mana >= mana) {
		m_mana -= mana;
		system("CLS");
		if (succesAttaque(90)) {
			
			
			m_vie += sequence[0];
			if (m_vie > m_vieTot) {
				m_vie = m_vieTot;
			}
			cout << "Soin de " << sequence[0] << accent(" | coût en mana: ") << mana << endl;
			m_feed = "Soin de " + to_string(sequence[0]);
		}
		else {
			cout << accent("Soin échoué!") << endl;
			m_feed = "Soin échoué!";
		}
	}
	else {
		cout << accent("Vous n'avez pas assé de mana") << endl;
		m_feed = accent("Soin échoué!");
	}
}
