#pragma once

#include <iostream>
#include "Namirnica.h"
using namespace std;

class Sastojak
{
private:
	Namirnica namirnica;
	int kolicina;
public:
	// Konstruktori
	Sastojak(Namirnica namirnica = Namirnica(), int kolicina = 0);
	// Getteri
	Namirnica dohvati_namirnica() const;
	int dohvati_kolicina() const;
	// Metode
	int odredi_nutritivnu_vrednost() const;
	// Operatori
	friend ostream& operator<<(ostream& os, const Sastojak& s);
};

