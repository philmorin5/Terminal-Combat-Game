#include <iostream>
#include "Paysan.h"
#include "fonction.h"

using namespace std;

Paysan::Paysan()  { //Constructeur

}
Paysan::Paysan(string nom):m_nom(nom),m_vie(0), m_arme("poings") { //Constructeur surcharg�

}
Paysan::~Paysan() { //Destructeur

							// Vide pour le moment car pas d'allocation de m�moire
}


/****************************************************************************
Entr�e : un int qui repr�sente les d�gats inflig�s
Sortie : Aucune
R�le : D�duit le nombre de d�gats re�us de l'attribut m_vie du personnage
*****************************************************************************/
void Paysan::recevoirDegats(int nbDegats) {
	m_vie -= nbDegats; 	//On enl�ve le nombre de d�g�ts re�us � la vie du personnage

	if (m_vie < 0) {//Pour �viter d'avoir une vie n�gative

		m_vie = 0; //On met la vie � 0 (cela veut dire mort)
	}
}


/****************************************************************************
Entr�e : Aucune
Sortie : Un bool�en
R�le : v�rifie si l'attribut m_vie est plus grand que 0(envie) retourne vrai si
c'est le cas sinon(mort) retourne faux.
*****************************************************************************/
bool Paysan::estVivant() const {
	if (m_vie > 0) { // Plus de 0 de vie ?

		return true; //VRAI, il est vivant !
	}
	else {
		return false; //FAUX, il n'est plus vivant !

	}
}

/****************************************************************************
Entr�e : Aucune
Sortie : Aucune
R�le :	Affiche dans la console les informations de base du personnage
*****************************************************************************/
void Paysan::affichage() const {
	cout << "Bonjour, je m'appelle " << m_nom << "." << endl;
	cout << "J'ai encore " << m_vie << " points de vie." << endl;
}
/****************************************************************************
Entr�e : Aucune
Sortie : String
R�le :	Permet d'ajouter l'action � la feed
*****************************************************************************/
string Paysan::feed() {
return m_feed;
}
/****************************************************************************
Entr�e : Aucune
Sortie : Aucune
R�le :	Permet de lire le nom
************+*****************************************************************/
string Paysan::getNom() {
	return m_nom;
}
