#include "Osoba.h"

Osoba::Osoba(string ime, string JMBG, const Datum& datum_rodjenja)
{
	this->ime = ime;
	this->JMBG = JMBG;
	this->datum_rodjenja = datum_rodjenja;
}

string Osoba::dohvati_ime() const
{
	return this->ime;
}

string Osoba::dohvati_JMBG() const
{
	return this->JMBG;
}

Datum Osoba::dohvati_datum_rodjenja() const
{
	return this->datum_rodjenja;
}

ostream& operator<<(ostream& os, const Osoba& o)
{
	return os << "O(" << o.ime << "," << o.JMBG << "," << o.datum_rodjenja << ")";
}
