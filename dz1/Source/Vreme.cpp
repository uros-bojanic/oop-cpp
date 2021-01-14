#include "Vreme.h"

Vreme::Vreme(int c, int m, int s)
{
	cas = c;
	min = m;
	sek = s;
}

bool operator>(const Vreme& v1, const Vreme& v2)
{
	return (v1.cas * 3600 + v1.min * 60 + v1.sek) > (v2.cas * 3600 + v2.min * 60 + v2.sek);
}

ostream& operator<<(ostream& os, const Vreme& v)
{
	return os << v.cas << ":" << v.min << ":" << v.sek << endl;
}
