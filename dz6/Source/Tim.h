#pragma once

#include <string>
#include <iostream>
#include "Igrac.h"
using namespace std;

class Tim
{
protected:
	string naziv;
	int max_broj_igraca;
	Igrac** igraci;
	// Metode
	void kopiraj(const Tim& l);
	void premesti(Tim& l);
	void isprazni();
public:
	// Konstruktor
	Tim(string naziv = "", int max_broj_igraca = 0);
	Tim(const Tim& t);
	Tim(Tim&& t);
	Tim& operator=(const Tim& t);
	Tim& operator=(Tim&& t);
	~Tim();
	// Metode
	virtual void prikljuci_igraca(int pozicija, const Igrac* igrac);
	int dohvati_broj_igraca() const;
	int dohvati_vrednost_tima() const;
	void azuriraj_vrednost_igraca(int p);
	virtual void pisi(ostream& os) const;
	// Operatori
	Igrac& operator[](int i) const;
	friend bool operator==(const Tim& t1, const Tim& t2);
	friend ostream& operator<<(ostream& os, const Tim& t);
};

