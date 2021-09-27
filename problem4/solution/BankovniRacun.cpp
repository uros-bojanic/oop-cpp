#include "BankovniRacun.h"
#include "Greske.h"

BankovniRacun::BankovniRacun(Osoba* vlasnik, int broj_racuna)
{
	this->vlasnik = vlasnik;
	this->broj_racuna = broj_racuna;
	this->iznos = 0;
}

Osoba& BankovniRacun::dohvati_vlasnik() const
{
	return *(this->vlasnik);
}

int BankovniRacun::dohvati_broj_racuna() const
{
	return this->broj_racuna;
}

int BankovniRacun::dohvati_iznos() const
{
	return this->iznos;
}

bool BankovniRacun::prebaci(int iznos, BankovniRacun& b)
{
	if (iznos < 0) throw GIznosNegativan();
	if (this->iznos >= iznos) {
		this->iznos -= iznos;
		b += iznos;
		return true;
	}
	return false;
}

void BankovniRacun::operator+=(int iznos)
{
	if (iznos < 0) throw GIznosNegativan();
	this->iznos += iznos;
}

void BankovniRacun::pisi(ostream& os) const
{
	os << "R: " << this->broj_racuna << " = " << this->iznos;
}

ostream& operator<<(ostream& os, const BankovniRacun& b)
{
	b.pisi(os);
	return os;
}
