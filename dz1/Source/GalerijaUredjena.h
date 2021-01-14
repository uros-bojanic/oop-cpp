#ifndef _GalerijaUredjena_h_
#define _GalerijaUredjena_h_

#include "Galerija.h"

class GalerijaUredjena :
	public Galerija
{
public:
	// Konstruktor
	GalerijaUredjena();

	// Operatori
	void operator+= (const Slika& s) override;
};

#endif