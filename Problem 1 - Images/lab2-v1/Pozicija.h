#ifndef _Pozicija_h_
#define _Pozicija_h_

#include <iostream>

using namespace std;

class Pozicija
{
private:
	int vrsta, kolona;

public:
	// Konstruktori
	Pozicija(int vrs = 0, int kol = 0);

	// Getteri
	int get_vrsta() const;
	int get_kolona() const;

	// Operatori
	friend double operator-(const Pozicija& poz1, const Pozicija& poz2);
};

#endif