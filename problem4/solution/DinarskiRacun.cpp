#include "DinarskiRacun.h"

DinarskiRacun::DinarskiRacun(Osoba* vlasnik, int broj_racuna) : BankovniRacun(vlasnik, broj_racuna)
{
}

string DinarskiRacun::dohvati_oznaka() const
{
	return "RSD";
}

void DinarskiRacun::pisi(ostream& os) const
{
	BankovniRacun::pisi(os);
	os << " - " << this->dohvati_oznaka();
}
