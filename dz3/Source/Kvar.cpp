#include "Kvar.h"

ostream& operator<<(ostream& os, Kvar& kv)
{
	return os << kv.datum << "-" << kv.opis << endl;
}

Kvar::Kvar(string s, Datum d, bool o)
{
	opis = s;
	datum = d;
	otklonjenost = o;
}

string Kvar::get_opis()
{
	return opis;
}

Datum& Kvar::get_datum()
{
	return datum;
}

bool Kvar::get_otklonjenost()
{
	return otklonjenost;
}

void Kvar::set_otklonjenost(bool b)
{
	otklonjenost = b;
}
