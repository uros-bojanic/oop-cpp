#include "Namirnica.h"

Namirnica::Namirnica(string naziv, NutritivnaVrednost nutritivna_vrednost, bool posno)
{
	this->naziv = naziv;
	this->nutritivna_vrednost = nutritivna_vrednost;
	this->posno = posno;
}

string Namirnica::dohvati_naziv() const
{
	return naziv;
}

NutritivnaVrednost Namirnica::dohvati_nutritivna_vrednost() const
{
	return nutritivna_vrednost;
}

bool Namirnica::dohvati_posno() const
{
	return posno;
}

bool operator==(const Namirnica& n1, const Namirnica& n2)
{
	return (n1.naziv == n2.naziv);
}

ostream& operator<<(ostream& os, const Namirnica& n)
{
	return os << n.naziv << " - " << n.nutritivna_vrednost;
}
