#pragma once

#include <string>


class Paysan {


public:
	Paysan();
	Paysan(std::string nom);
	~Paysan();
	void recevoirDegats(int nbDegats);
	std::string getNom();
	virtual void affichage() const =0;
	virtual void stats() const = 0;
	virtual bool menu(Paysan* cible) = 0;
	virtual void attaqueArme(Paysan* cible) = 0;
	virtual void attaqueSpecial(Paysan* cible) = 0;
	std::string feed();
	bool estVivant() const;

protected:
	int m_vie;
	std::string m_nom;
	std::string m_arme;
	std::string m_feed;
};