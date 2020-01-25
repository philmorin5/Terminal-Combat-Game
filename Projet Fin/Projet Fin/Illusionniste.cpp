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

Illusionniste::Illusionniste(string nom) : Magicien(nom,0)  { //Constructeur surcharg�
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
cout << accent("G�n�ration de la vie : ") << tVie << "=" << m_vie << endl;


	sequenceM = diceRoll(1, 1, 20);
	for (int ctr(0); ctr < sequenceM.size(); ctr++) {
		m_mana += sequenceM[ctr];
		tMana += to_string(sequenceM[ctr]);
		if (ctr < (sequenceM.size() - 1))
		tMana += "+";
		
	}cout << accent("G�n�ration du mana : ") << tMana << "=" << m_mana << endl;
}
Illusionniste::~Illusionniste() { //Destructeur

}
/****************************************************************************
Entr�e : objet Paysan
Sortie : Aucune
R�le : Affiche les menus des actions
*****************************************************************************/
bool Illusionniste::menu(Paysan* cible) {
	int cmd;


	cout << m_nom<<" faites votre choix" << endl;
	cout << accent("1. Boule de feu (2d20 d�gat,1d20 mana,75% de r�ussite)\n2. Attaque avec dague (3d4 d�gat, 90% de r�ussite)\n3. Aveuglement (2d6 d�gat, 50% de r�ussite)") << endl;

	do { //s�lection de l'attaque
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
Entr�e : Aucune
Sortie : Aucune
R�le : Pr�sente le personnage
*****************************************************************************/
void Illusionniste::affichage() const {
	cout << accent(" s'appelle ") << m_nom << "." << endl;
	cout << accent("Il est un grand Illusionniste.\nIl est ") << m_vie << " de vie et "<<m_mana<<" de mana" << endl;
}
/****************************************************************************
Entr�e : object type Paysan en r�f�rence
Sortie : Aucune
R�le : D�duit le nombre de d�gats re�us de l'attribut m_vie du personnage
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
		cout << accent("Attaque �chou�!") << endl;
		m_feed = accent("Attaque �chou�!");
	}
}

/****************************************************************************
Entr�e : object type Paysan en r�f�rence
Sortie : Aucune
R�le : D�duit le nombre de d�gats re�us de l'attribut m_vie du personnage
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
			cout << accent("Attaque �chou�!") << endl;
			m_feed = accent("Attaque �chou�!");
			return false;
		}
	


}
