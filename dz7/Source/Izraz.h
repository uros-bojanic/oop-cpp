#pragma once
#include "Lista.h"
#include "Element.h"

class Izraz :
	public Lista<Element>
{
public:
	// Konstruktori
	Izraz();
	// Metode
	Izraz* polimorfno_kopiraj() const {
		return new Izraz(*this);
	}
};

