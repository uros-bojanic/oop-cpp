#include "Smestaj.h"
#include "Greske.h"

Smestaj::Smestaj(const Destinacija& destinacija, Tip tip, string naziv, int broj_zvezdica, double cena_po_danu)
{
	if (broj_zvezdica < 1 || broj_zvezdica > 5) throw GNeispravanBrojZvezdica();
	this->destinacija = destinacija;
	this->tip = tip;
	this->naziv = naziv;
	this->broj_zvezdica = broj_zvezdica;
	this->cena_po_danu = cena_po_danu;
}

const Destinacija& Smestaj::dohvati_destinacija() const
{
	return destinacija;
}

Smestaj::Tip Smestaj::dohvati_tip() const
{
	return tip;
}

string Smestaj::dohvati_naziv() const
{
	return naziv;
}

int Smestaj::dohvati_broj_zvezdica() const
{
	return broj_zvezdica;
}

double Smestaj::dohvati_cena_po_danu() const
{
	return cena_po_danu;
}

ostream& operator<<(ostream& os, const Smestaj& s)
{
	os << s.naziv << " ";
	for (int i = 0; i < s.broj_zvezdica; i++)
		os << "*";
	return os;
}
