#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <iostream>
#include <iomanip>
#include "Korisnik.h"

using namespace std;

class Obavestenje
{
private:
	int id;
	time_t t;
	bool procitano;
	Korisnik* kreator;
	static int count;

public:
	// Konstruktor
	Obavestenje(Korisnik* korisnik);

	// Getteri
	int get_id() const;
	bool get_procitano() const;
	Korisnik* get_kreator() const;

	// Setteri
	void procitaj();

	// Operatori
	friend ostream& operator<<(ostream& os, const Obavestenje& o);

};

