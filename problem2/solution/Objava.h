#pragma once

#include "Obavestenje.h"

class Objava :
	public Obavestenje
{
private:
	string tekst;

public:
	// Konstruktori
	Objava(Korisnik* korisnik, string s);
	Objava(Obavestenje o, string s);

	// Operatori
	// ??? static_cast?
};

