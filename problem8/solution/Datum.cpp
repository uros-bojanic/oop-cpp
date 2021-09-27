#include "Datum.h"
#include "Greske.h"

Datum::Datum(int dan, int mes, int god)
{
	if (dan < 1 || dan > 31 || mes < 1 || mes > 12 || god < 1) throw GNeispravanDatum();
	this->dan = dan;
	this->mes = mes;
	this->god = god;
}

int Datum::dohvati_dan() const
{
	return dan;
}

int Datum::dohvati_mes() const
{
	return mes;
}

int Datum::dohvati_god() const
{
	return god;
}

int operator-(const Datum& d1, const Datum& d2)
{
	int n1 = d1.god * 365 + d1.mes * 30 + d1.dan;
	int n2 = d2.god * 365 + d2.mes * 30 + d2.dan;
	if (n1 > n2) return n1 - n2;
	return 0;
}

ostream& operator<<(ostream& os, const Datum& d)
{
	return os << d.dan << "." << d.mes << "." << d.god << ".";
}
