#include "Igrac.h"

Igrac::Igrac(string ime, int vrednost)
{
	this->ime = ime;
	this->vrednost = vrednost;
}

string Igrac::dohvati_ime() const
{
	return ime;
}

int Igrac::dohvati_vrednost() const
{
	return vrednost;
}

void Igrac::povecaj_vrednost(int p)
{
	this->vrednost += (this->vrednost * p) / 100;
}

void Igrac::smanji_vrednost(int p)
{
	this->vrednost -= (this->vrednost * p) / 100;
}

bool operator==(const Igrac& i1, const Igrac& i2)
{
	return (i1.ime == i2.ime && i1.vrednost == i2.vrednost);
}

ostream& operator<<(ostream& os, const Igrac& i)
{
	return os << i.ime << "#" << i.vrednost;
}
