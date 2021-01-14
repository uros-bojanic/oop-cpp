#include "Destinacija.h"

Destinacija::Destinacija(string naziv, string opis)
{
	this->naziv = naziv;
	this->opis = opis;
	prosecna_ocena = broj_ocena = 0;
}

string Destinacija::dohvati_naziv() const
{
	return naziv;
}

string Destinacija::dohvati_opis() const
{
	return opis;
}

int Destinacija::dohvati_prosecna_ocena() const
{
	return prosecna_ocena;
}

void Destinacija::oceni(unsigned int ocena)
{
	if (ocena <= 5) {
		prosecna_ocena *= broj_ocena;
		prosecna_ocena += ocena;
		prosecna_ocena /= ++broj_ocena;
	}
}

bool operator>(const Destinacija& d1, const Destinacija& d2)
{
	return (d1.prosecna_ocena > d2.prosecna_ocena);
}

ostream& operator<<(ostream& os, const Destinacija& d)
{
	return os << "[" << d.prosecna_ocena << "] " << d.naziv << " (" << d.opis << ")";
}
