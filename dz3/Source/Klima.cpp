#include "Klima.h"

Klima::Klima(int br, string pr) : Uredjaj(pr)
{
	broj_kvadrata = br;
}

void Klima::postavi_garanciju(Datum poc)
{
	Datum kr{poc.get_dan(), poc.get_mes(), poc.get_god() + 5};
	garancija = new Garancija(poc, kr);
}

bool operator==(Klima& kl1, Klima& kl2)
{
	return (kl1.proizvodjac == kl2.proizvodjac && kl1.broj_kvadrata == kl2.broj_kvadrata);
}

ostream& operator<<(ostream& os, Klima& kl)
{
	return os << kl.proizvodjac << ":" << kl.id << "#klima-" << kl.broj_kvadrata << endl;
}
