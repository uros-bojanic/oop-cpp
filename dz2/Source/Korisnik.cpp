#include "Korisnik.h"

string Korisnik::get_ime() const
{
	return ime;
}

ostream& operator<<(ostream& os, const Korisnik& k)
{
	return os << k.ime << endl;
}
