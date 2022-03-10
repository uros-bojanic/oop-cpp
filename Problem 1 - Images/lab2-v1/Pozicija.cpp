#include "Pozicija.h"
#include <math.h>

double operator-(const Pozicija& poz1, const Pozicija& poz2)
{
	double dx = abs((double)poz1.vrsta - poz2.vrsta);
	double dy = abs((double)poz1.kolona - poz2.kolona);
	return dx + dy;
}

Pozicija::Pozicija(int vrs, int kol)
{
	vrsta = vrs;
	kolona = kol;
}

int Pozicija::get_vrsta() const
{
	return vrsta;
}

int Pozicija::get_kolona() const
{
	return kolona;
}
