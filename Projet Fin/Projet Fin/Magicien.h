#pragma once


#include <string>
#include "Paysan.h"

class Magicien : public Paysan {


public:
	Magicien();
	Magicien(Magicien &objet);
	Magicien(std::string nom);
	Magicien(std::string nom, int surcharge);
	~Magicien();
	void affichage() const;
	virtual void stats() const;
	virtual bool menu(Paysan* cible);
	virtual void attaqueArme(Paysan* cible);
	virtual void attaqueSpecial(Paysan* cible);

protected:
	int m_mana;
};