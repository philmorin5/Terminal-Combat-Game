#include <iostream>
#include <string>
#include <vector>
#include "Illusionniste.h"
#include "fonction.h"

using namespace std;

Illusionniste::Illusionniste() { //constructeur

}
Illusionniste::Illusionniste(Illusionniste &objet) { //constructeur de copie
}

Illusionniste::Illusionniste(string nom) : Magicien(nom,0)  { //Constructeur surchargé
	vector<int> sequenceV;
	vector<int> sequenceM;
	string tVie;
	string tMana;


	m_arme = accent("Dague");
	cout << endl;
	sequenceV = diceRoll(3, 1, 20);
	for (int ctr(0); ctr < sequenceV.size(); ctr++) {
		m_vie += sequenceV[ctr];
		tVie += to_string(sequenceV[ctr]);
		if(ctr < (sequenceV.size()-1))
		tVie += "+";
		
	}
cout << accent("Génération de la vie : ") << tVie << "=" << m_vie << endl;


	sequenceM = diceRoll(1, 1, 20);
	for (int ctr(0); ctr < sequenceM.size(); ctr++) {
		m_mana += sequenceM[ctr];
		tMana += to_string(sequenceM[ctr]);
		if (ctr < (sequenceM.size() - 1))
		tMana += "+";
		
	}cout << accent("Génération du mana : ") << tMana << "=" << m_mana << endl;
}
Illusionniste::~Illusionniste() { //Destructeur

}
/****************************************************************************
Entrée : objet Paysan
Sortie : Aucune
Rôle : Affiche les menus des actions
*****************************************************************************/
bool Illusionniste::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" faites votre choix" << endl;
	cout << accent("1. Boule de feu (2d20 dégat,1d20 mana,75% de réussite)\n2. Attaque avec dague (3d4 dégat, 90% de réussite)\n3. Aveuglement (2d6 dégat, 50% de réussite)") << endl;

	do { //sélection de l'attaque
		cin >> cmd;
	} while (!verifInt(cmd, 1, 3));

	switch (cmd) {

	case 1:
		attaqueSpecial(cible);
		return false;
		break;

	case 2:
		attaqueArme(cible);
		return false;
		break;
	case 3:
		return aveuglement(cible);
		break;
		
	}
}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle : Présente le personnage
*****************************************************************************/
void Illusionniste::affichage() const {
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un grand Illusionniste.\nIl est ") << m_vie << " de vie et "<<m_mana<<" de mana" << endl;
}
/****************************************************************************
Entrée : object type Paysan en référence
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Illusionniste::attaqueArme(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(3, 1, 4);
	int degat(0);
	string tDegat;
	system("CLS");
	if (succesAttaque(90)) {

		for (int ctr(0); ctr < sequence.size(); ctr++) {
			degat += sequence[ctr];
			
		}

		cible->recevoirDegats(degat);

		cout << accent("Coup de dague: ") << degat << endl;
		m_feed = "Coup de dague: " + to_string(degat);
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
bool Illusionniste::aveuglement(Paysan* cible) {
	vector<int> sequence;
	sequence = diceRoll(2, 1, 6);
	int degat(0);
	int mana(0);
	string tDegat;

	system("CLS");
		if (succesAttaque(50)) {

			for (int ctr(0); ctr < sequence.size(); ctr++) {
				degat += sequence[ctr];
				
			}

			cible->recevoirDegats(degat);

			cout << accent("Lance aveuglement: ") << degat << endl;
			m_feed = "Lance aveuglement: " + to_string(degat);
			cout << "Votre ennemi passe son tour" << endl;
			return true;
		}
		else {
			cout << accent("Attaque échoué!") << endl;
			m_feed = accent("Attaque échoué!");
			return false;
		}
	


}
