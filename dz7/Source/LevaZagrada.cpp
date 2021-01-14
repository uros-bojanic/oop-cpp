#include "LevaZagrada.h"

LevaZagrada::LevaZagrada() : Element()
{
}

LevaZagrada* LevaZagrada::polimorfno_kopiraj() const
{
	return new LevaZagrada(*this);
}

char LevaZagrada::dohvati_vrstu() const
{
	return '(';
}

string LevaZagrada::dohvati_natpis() const
{
	return "(";
}
