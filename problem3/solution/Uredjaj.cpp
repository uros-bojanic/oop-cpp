#include "Uredjaj.h"

int Uredjaj::count = 0;

bool operator==(const Uredjaj& u1, const Uredjaj& u2)
{
	return u1.proizvodjac == u2.proizvodjac;
}

ostream& operator<<(ostream& os, const Uredjaj& ur)
{
	return os << ur.proizvodjac << ":" << ur.id << endl;
}

Uredjaj::Uredjaj(string pr)
{
	proizvodjac = pr;
	garancija = nullptr;
	id = ++count;
}

void Uredjaj::postavi_garanciju(Garancija* g)
{
	garancija = g;
}

void Uredjaj::postavi_garanciju(Datum poc, Datum kr)
{
	garancija = new Garancija(poc, kr);
}

Garancija& Uredjaj::dohvati_garanciju()
{
	return (*garancija);
}
