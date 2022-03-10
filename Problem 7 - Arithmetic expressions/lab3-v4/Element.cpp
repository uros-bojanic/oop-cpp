#include "Element.h"

ostream& operator<<(ostream& os, const Element& e)
{
	return os << e.dohvati_natpis();
}