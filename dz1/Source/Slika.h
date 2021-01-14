#ifndef _Slika_h_
#define _Slika_h_

#include <iostream>
#include "Piksel.h"
#include "Pozicija.h"
#include "Vreme.h"

using namespace std;

class Slika
{
protected:
	int sirina, visina;
	Piksel** slika;
	Vreme nastanak;

public:
	// Konstruktori
	Slika(int sir = 0, int vis = 0, Vreme nas = { 0,0,0 });
	Slika(const Slika& s);

	// Destruktor
	~Slika();

	// Getteri
	int dohvati_sirinu() const;
	int dohvati_visinu() const;
	int dohvati_velicinu() const;
	Vreme dohvati_vreme_nastanka() const;

	// Metode
	virtual void postavi_piksel(const Piksel& p, const Pozicija& poz);

	// Operatori
	Piksel operator[](const Pozicija& poz);
	friend ostream& operator<<(ostream& os, const Slika& s);
	void operator= (const Slika& s);
};

#endif