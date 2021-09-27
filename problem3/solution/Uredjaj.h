#pragma once

#include <string>
#include "Garancija.h"

using namespace std;

class Uredjaj
{
protected:
	string proizvodjac;
	Garancija* garancija;
	int id;
	static int count;

public:
	// Konstruktori
	Uredjaj(string pr = "");
	Uredjaj(const Uredjaj& k) = delete;

	// Metode
	void postavi_garanciju(Garancija* g);
	void postavi_garanciju(Datum poc, Datum kr);
	Garancija& dohvati_garanciju();

	// Operatori
	friend bool operator==(const Uredjaj& u1, const Uredjaj& u2);
	friend ostream& operator<<(ostream& os, const Uredjaj& ur);
};

