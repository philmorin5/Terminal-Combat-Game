#include <iostream>
#include "Paysan.h"
#include "fonction.h"

using namespace std;

Paysan::Paysan()  { //Constructeur

}
Paysan::Paysan(string nom):m_nom(nom),m_vie(0), m_arme("poings") { //Constructeur surchargé

}
Paysan::~Paysan() { //Destructeur

							// Vide pour le moment car pas d'allocation de mémoire
}


/****************************************************************************
Entrée : un int qui représente les dégats infligés
Sortie : Aucune
Rôle : Déduit le nombre de dégats reçus de l'attribut m_vie du personnage
*****************************************************************************/
void Paysan::recevoirDegats(int nbDegats) {
	m_vie -= nbDegats; 	//On enlève le nombre de dégâts reçus à la vie du personnage

	if (m_vie < 0) {//Pour éviter d'avoir une vie négative

		m_vie = 0; //On met la vie à 0 (cela veut dire mort)
	}
}


/****************************************************************************
Entrée : Aucune
Sortie : Un booléen
Rôle : vérifie si l'attribut m_vie est plus grand que 0(envie) retourne vrai si
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
Entrée : Aucune
Sortie : Aucune
Rôle :	Affiche dans la console les informations de base du personnage
*****************************************************************************/
void Paysan::affichage() const {
	cout << "Bonjour, je m'appelle " << m_nom << "." << endl;
	cout << "J'ai encore " << m_vie << " points de vie." << endl;
}
/****************************************************************************
Entrée : Aucune
Sortie : String
Rôle :	Permet d'ajouter l'action à la feed
*****************************************************************************/
string Paysan::feed() {
return m_feed;
}
/****************************************************************************
Entrée : Aucune
Sortie : Aucune
Rôle :	Permet de lire le nom
************+*****************************************************************/
string Paysan::getNom() {
	return m_nom;
}
