#include "Sastojak.h"

Sastojak::Sastojak(Namirnica namirnica, int kolicina)
{
	this->namirnica = namirnica;
	this->kolicina = kolicina;
}

Namirnica Sastojak::dohvati_namirnica() const
{
	return namirnica;
}

int Sastojak::dohvati_kolicina() const
{
	return kolicina;
}

int Sastojak::odredi_nutritivnu_vrednost() const
{
	return namirnica.dohvati_nutritivna_vrednost().ukupan_broj_kalorija() * kolicina / 100;
}

ostream& operator<<(ostream& os, const Sastojak& s)
{
	return os << "[" << s.odredi_nutritivnu_vrednost() << " kcal] " << s.kolicina << "g x " << s.namirnica;
}
