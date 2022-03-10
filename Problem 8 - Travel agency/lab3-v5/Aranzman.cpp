#include "Aranzman.h"
#include "Greske.h"

Aranzman::Aranzman(const Destinacija& destinacija, const Datum& datum_pocetka, const Datum& datum_kraja) : datum_pocetka(datum_pocetka), datum_kraja(datum_kraja)
{
	this->destinacija = const_cast<Destinacija*>(&destinacija);
	this->prevoz = nullptr;
	this->smestaj = nullptr;
}

const Destinacija& Aranzman::dohvati_destinacija() const
{
	return *destinacija;
}

const Datum& Aranzman::dohvati_datum_pocetka() const
{
	return datum_pocetka;
}

const Datum& Aranzman::dohvati_datum_kraja() const
{
	return datum_kraja;
}

void Aranzman::postavi_smestaj(const Smestaj& smestaj)
{
	if (smestaj.dohvati_destinacija().dohvati_naziv() != (*this->destinacija).dohvati_naziv()) throw GNeispravnaDestinacija();
	this->smestaj = const_cast<Smestaj*>(&smestaj);
}

void Aranzman::postavi_prevoz(const Prevoz& prevoz)
{
	if (prevoz.dohvati_destinacija().dohvati_naziv() != (*this->destinacija).dohvati_naziv()) throw GNeispravnaDestinacija();
	this->prevoz = const_cast<Prevoz*>(&prevoz);
}

int Aranzman::dohvati_trajanje_aranzmana() const
{
	return (datum_kraja - datum_pocetka);
}

double Aranzman::dohvati_cenu_aranzmana() const
{
	if (smestaj == nullptr) throw GNemaSmestaja();
	if (prevoz == nullptr) throw GNemaPrevoza();
	return (*prevoz).dohvati_cena_prevoza() + dohvati_trajanje_aranzmana() * (*smestaj).dohvati_cena_po_danu();
}

ostream& operator<<(ostream& os, const Aranzman& a)
{
	os << *a.destinacija;
	if (a.smestaj != nullptr) os << endl << "\t" << *a.smestaj;
	if (a.prevoz != nullptr) os << endl << "\t" << a.dohvati_cenu_aranzmana();
	return os;
}
