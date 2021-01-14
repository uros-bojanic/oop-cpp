#pragma once
#include "BankovniRacun.h"
class DinarskiRacun :
	public BankovniRacun
{
public:
	// Konstruktor
	DinarskiRacun(Osoba* vlasnik, int broj_racuna);
	// Metode
	string dohvati_oznaka() const override;
	void pisi(ostream& os) const override;
};

