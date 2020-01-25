#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "fonction.h"
#include "Paysan.h"
#include "Guerrier.h"
#include "Pretre.h"
#include "Magicien.h"
#include "Illusionniste.h"

using namespace std;

int main() {
	srand(time(NULL));

	Paysan *perso1(0);
	Paysan *perso2(0);
	int select1, select2, tourPerso1(0), nbTour(1), rejouer(0);
	string nom1, nom2;
	boolean isIllu1(false), isIllu2(false), passeTour(false), aveugle(false);
	string feed,feedReset;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	


	do{
	system("CLS");

		rejouer = 0;
		//Presentation et information du jeu

	cout << accent("Bienvenue dans Le Monde d'Azeroth.\nCe jeu a été réalisé par Philippe Morin et Louis Côté dans le cadre du programme science informatique et mathématique.\n") << endl;
	cout << accent("\n                  ---------------Règles----------------\n") << endl;
	cout << accent("Vous incarnerez un combattant dans ce jeu tour par tour!\nVotre but: Éliminé votre adversaire!\nIl n'y aura qu'un seul survivant..") << endl;

	system("PAUSE");
	system("CLS");

	
	cout << accent("Vous avez le choix entre 4 classes :") << endl;
	cout << accent("\n\nLe guerrier possède(7d20) de vie, il n'a pas de mana et il a une hache (4d4) \nLe prêtre possède (5d20) de vie, (2d20) de mana et a un marteau (2d6)") << endl;
	cout << accent("Le magicien possède (4d20) de vie, (3d20) de mana et a une épée courte (2d4)\nL'illusionniste possède (3d20) de vie, (1d20) de mana et a une dague (3d4),\nil commence en premier et peut faire passer des tours\n") << endl;
	cout << accent("ex. 4d5 signifie le résultat de 4 lancés de dé allant jusqu'à 5") << endl;

	system("PAUSE");
	system("CLS");

	cout << "Choisisser votre nom"<<endl;
	cout << "Nom: ";
	cin >> nom1;
	cin.ignore();

	system("PAUSE");
	system("CLS");

	cout << accent("Choisissez votre personnage :\n1. Guérrier\n2. Prêtre\n3. Magicien\n4. Illusionniste\n_______________________") << endl;  //Le joueur 1 choisit son personnage
	cout << "Classe: ";

	do { //Valide la saisie
		cin >> select1;
	} while (!verifInt(select1, 1, 4));


	switch (select1) { //Switch qui cré la classe choisit
	case 1:
		perso1 = new Guerrier(nom1);
		break;
	case 2:
		perso1 = new Pretre(nom1);
		break;
	case 3:
		perso1 = new Magicien(nom1);
		break;
	case 4:
		perso1 = new Illusionniste(nom1);
		isIllu1 = true;
		break;
	}
	cout << endl;
	system("PAUSE");
	system("CLS");


	cout << "Choisisser votre nom" << endl;
	cout << "Nom: ";
	cin >> nom2;
	cin.ignore();

	system("PAUSE");
	system("CLS");

	cout << accent("Choisissez votre personnage :\n1. Guérrier\n2. Prêtre\n3. Magicien\n4. Illusionniste\n_______________________") << endl;  //Le joueur 1 choisit son personnage
	cout << "Classe: ";

	do {  //valide la saisie
		cin >> select2;
	} while (!verifInt(select2, 1, 4));



	switch (select2) {  //Switch qui cré la classe choisit
	case 1:
		perso2 = new Guerrier(nom2);
		break;
	case 2:
		perso2 = new Pretre(nom2);
		break;
	case 3:
		perso2 = new Magicien(nom2);
		break;
	case 4:
		perso2 = new Illusionniste(nom2);
		isIllu2 = true;
		break;
	}

	// afiche les infos des personnages

	cout << endl;
	system("PAUSE");
	system("CLS");
	cout << "Joueur 1";
	perso1->affichage();
	cout << endl;
	cout << "Joueur 2";
	perso2->affichage();
	system("PAUSE");
	system("CLS");


	if (!isIllu1&&!isIllu2) {  // Tirage au sort pour savoir qui commence quand 0 illusionniste
		if (trouverAleatoire(1, 2) == 1) {
			tourPerso1 = 1;
			cout << accent("Le hasard a choisi que le joueur 1 commencera.") << endl;
		}
		else {
			tourPerso1 = 2;
			cout << accent("Le hasard a choisi que le joueur 2 commencera.") << endl;
		}
	}
	else if (isIllu1&&isIllu2) {   // Tirage au sort pour savoir qui commence quand 2 illusionnistes
		if (trouverAleatoire(1, 2) == 1) {
			tourPerso1 = 1;
			cout << accent("Le hasard a choisi que le joueur 1 commencera.") << endl;
		}
		else {
			tourPerso1 = 2;
			cout << accent("Le hasard a choisi que le joueur 2 commencera.") << endl;
		}
	}
	else if (isIllu1&&!isIllu2) {   // Joueur 1 commence
		tourPerso1 = 1;
		cout << accent("Le joueur 1 commence car il est un puissant illusionniste.") << endl;
	}

	else if (!isIllu1&&isIllu2) { // joueur 2 commence
		tourPerso1 = 2;
		cout << accent("Le joueur 2 commence car il est un puissant illusionniste.") << endl;
	}
	system("PAUSE");
	system("CLS");

	do {   //Roulement et exécution des tours

		nbTour++;

		if (tourPerso1 == 1) {

			cout << "Tour : " << nbTour << endl << endl;
			cout << perso1->getNom() << endl;
			perso1->stats();
			cout << endl << endl;
			
			cout << perso2->getNom() << endl;
			perso2->stats();
			cout << endl << endl;
			
			aveugle = perso1->menu(perso2);
			if (!aveugle)
				tourPerso1 = 2;
            feed += perso1->getNom() + " - " + perso1->feed()+ "\n";

		}
		else {
			nbTour--;
			cout << "Tour : " << nbTour << endl << endl;
			cout << perso2->getNom() << endl;
			perso2->stats();
			cout << endl << endl;
		
			cout << perso1->getNom() << endl;
			perso1->stats();

			cout << endl << endl;
		
			aveugle = perso2->menu(perso1);
			if (!aveugle)
				tourPerso1 = 1;
			feed += perso2->getNom() +" - " + perso2->feed() + "\n";
		
		}
		system("PAUSE");
		system("CLS");

	} while (perso1->estVivant() && perso2->estVivant()); //joue tant que les deux joueurs sont en vie


	//Informations de fin de combat

	cout << accent("Résumé du combat\n\n") << feed<<endl;
	if (perso1->estVivant()) {
		
		cout << perso1->getNom() <<" gagne le combat!" << endl;
	}
	else {
		
		cout <<perso2->getNom()<< " gagne le combat!" << endl;
	}

	system("PAUSE");
	system("CLS");
	cout << " Voulez-vous rejouer (1:oui | 2:non)" << endl;

	do {  //Option de rejouer
		cin >> rejouer;
	} while (!verifInt(rejouer, 1, 2));
	feed = feedReset;
}while (rejouer != 2); //Relance le jeu tant que le joueur veut rejouer


system("CLS");
cout << "Merci d'avoir jouer a notre jeu, fermeture de la session..." << endl;


delete perso1;
perso1 = 0;
delete perso2;
perso2;

	system("PAUSE");
	return 0;
}