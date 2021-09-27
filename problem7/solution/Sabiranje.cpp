#include "Sabiranje.h"

Sabiranje::Sabiranje() : BinarniOperator(1)
{
}

Sabiranje* Sabiranje::polimorfno_kopiraj() const
{
	return new Sabiranje(*this);
}

string Sabiranje::dohvati_natpis() const
{
	return "+";
}
