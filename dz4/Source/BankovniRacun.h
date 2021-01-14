#pragma once

#include <iostream>
#include "Osoba.h"
using namespace std;

class BankovniRacun
{
private:
	Osoba* vlasnik;
	int broj_racuna, iznos;
public:
	// Konstruktor
	BankovniRacun(Osoba* vlasnik, int broj_racuna);
	// Getteri
	Osoba& dohvati_vlasnik() const;
	int dohvati_broj_racuna() const;
	int dohvati_iznos() const;
	// Metode
	virtual string dohvati_oznaka() const = 0;
	bool prebaci(int iznos, BankovniRacun& b);
	// Operatori
	void operator+=(int iznos);
	virtual void pisi(ostream& os) const;
	friend ostream& operator<<(ostream& os, const BankovniRacun& b);
};

