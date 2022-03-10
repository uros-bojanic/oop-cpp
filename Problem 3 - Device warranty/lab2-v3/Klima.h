#pragma once

#include "Uredjaj.h"

using namespace std;

class Klima :
	public Uredjaj
{
private:
	int broj_kvadrata;

public:
	// Konstuktori
	Klima(int br = 0, string pr = "");

	// Metode
	void postavi_garanciju(Datum poc);

	// Operatori
	friend bool operator==(Klima& kl1, Klima& kl2);
	friend ostream& operator<<(ostream& os, Klima& kl);
};

