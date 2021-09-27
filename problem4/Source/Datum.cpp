#include "Datum.h"
#include "Greske.h"

Datum::Datum(int dan, int mes, int god)
{
	if (dan < 1 || dan > 31 || mes < 1 || mes > 12 || god < 0 || god > 2021) throw GPogresanDatum();
	this->dan = dan;
	this->mes = mes;
	this->god = god;
}

int Datum::dohvati_dan() const
{
	return this->dan;
}

int Datum::dohvati_mes() const
{
	return this->mes;
}

int Datum::dohvati_god() const
{
	return this->god;
}

bool operator==(const Datum& d1, const Datum& d2)
{
	return (d1.dan == d2.dan && d1.mes == d2.mes && d1.god == d2.god);
}

ostream& operator<<(ostream& os, const Datum& d)
{
	return os << d.dan << "." << d.mes << "." << d.god << ".";
}
