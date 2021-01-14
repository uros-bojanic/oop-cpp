#include "Obavestenje.h"

Obavestenje::Obavestenje(Korisnik* korisnik)
{
	id = ++count;
	t = time(0);
	procitano = false;
	kreator = korisnik;
}

int Obavestenje::get_id() const
{
	return id;
}

bool Obavestenje::get_procitano() const
{
	return procitano;
}

Korisnik* Obavestenje::get_kreator() const
{
	return kreator;
}

void Obavestenje::procitaj()
{
	procitano = true;
}

ostream& operator<<(ostream& os, const Obavestenje& o)
{
	return os << o.id << "|" << o.kreator->get_ime() << "-" << put_time(localtime(&o.t), "%T") << endl;
}

int Obavestenje::count = 0;