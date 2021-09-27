#include "DesnaZagrada.h"

DesnaZagrada::DesnaZagrada() : Element()
{
}

DesnaZagrada* DesnaZagrada::polimorfno_kopiraj() const
{
	return new DesnaZagrada(*this);
}

char DesnaZagrada::dohvati_vrstu() const
{
	return ')';
}

string DesnaZagrada::dohvati_natpis() const
{
	return ")";
}
