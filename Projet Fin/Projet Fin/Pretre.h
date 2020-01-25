#pragma once


#include <string>
#include "Paysan.h"

class Pretre : public Paysan {


public:
	Pretre();
	Pretre(Pretre &objet);
	Pretre(std::string nom);
	~Pretre();
	void affichage() const;
	virtual void stats() const;
	virtual bool menu(Paysan* cible);
	virtual void attaqueArme(Paysan* cible);
	virtual void attaqueSpecial(Paysan* cible);
	void soin();

protected:
	int m_vieTot;
	int m_mana;
};