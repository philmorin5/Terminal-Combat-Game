#pragma once
#pragma once

#include <string>
#include "Magicien.h"

class Illusionniste : public Magicien {


public:
	Illusionniste();
	Illusionniste(Illusionniste &objet);
	Illusionniste(std::string nom);
	~Illusionniste();
	void affichage() const;
	virtual bool menu(Paysan* cible);
	virtual void attaqueArme(Paysan* cible);
	virtual bool aveuglement(Paysan* cible);

};