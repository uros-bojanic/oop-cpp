#include "Datum.h"

Datum::Datum(int d, int m, int g)
{
	if (d >= 1 && d <= 31 && m >= 1 && m <= 12) {
		dan = d;
		mes = m;
		god = g;
	}
	else {
		exit(2);
	}
}

int Datum::get_dan()
{
	return dan;
}

int Datum::get_mes()
{
	return mes;
}

int Datum::get_god()
{
	return god;
}

int Datum::operator[](string s)
{
	if (s == "dan") return dan;
	else if (s == "mesec") return mes;
	else if (s == "godina") return god;
	return -1;
}

bool operator<(Datum& dat1, Datum& dat2)
{
	if (dat1.god < dat2.god) return true;
	else if (dat1.god == dat2.god) {
		if (dat1.mes < dat2.mes) return true;
		else if (dat1.mes == dat2.mes) {
			if (dat1.dan < dat2.dan) return true;
		}
	}
	return false;
}

ostream& operator<<(ostream& os, Datum& dat)
{
	return os << dat.dan << "." << dat.mes << "." << dat.god << ".";
}
