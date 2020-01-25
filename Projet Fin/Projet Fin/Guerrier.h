#pragma once

#include <string>
#include "Paysan.h"

class Guerrier : public Paysan {


public:
	Guerrier(); 
	Guerrier(std::string nom);
	Guerrier(Guerrier &objet);
	~Guerrier();
	void affichage() const;
	virtual void stats() const;
	virtual bool menu(Paysan* cible);
	virtual void attaqueArme(Paysan* cible);
	virtual void attaqueSpecial(Paysan* cible);

};