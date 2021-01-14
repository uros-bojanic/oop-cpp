#pragma once

#include "Destinacija.h"

class Prevoz
{
private:
	Destinacija destinacija;
	double cena;
public:
	// Konstruktori
	Prevoz(const Destinacija& destinacija = Destinacija(), double cena = 0.0);
	// Getteri
	const Destinacija& dohvati_destinacija() const;
	const double dohvati_cena_prevoza() const;
};

