#pragma once

#include <iostream>
#include "Datum.h"
using namespace std;

class Osoba
{
private:
	string ime, JMBG;
	Datum datum_rodjenja;
public:
	// Konstruktori
	Osoba(string ime = "", string JMBG = "", const Datum& datum_rodjenja = Datum());
	// Zabrana kopiranja
	Osoba(const Osoba& o) = delete;
	Osoba& operator=(const Osoba& o) = delete;
	// Getteri
	string dohvati_ime() const;
	string dohvati_JMBG() const;
	Datum dohvati_datum_rodjenja() const;
	// Operatori
	friend ostream& operator<<(ostream& os, const Osoba& o);
};

