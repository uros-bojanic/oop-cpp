#include "Prevoz.h"

Prevoz::Prevoz(const Destinacija& destinacija, double cena)
{
	this->destinacija = destinacija;
	this->cena = cena;
}

const Destinacija& Prevoz::dohvati_destinacija() const
{
	return destinacija;
}

const double Prevoz::dohvati_cena_prevoza() const
{
	return cena;
}
