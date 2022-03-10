#include "Operand.h"

Operand::Operand(string natpis) : Element()
{
	this->natpis = natpis;
}

Operand* Operand::polimorfno_kopiraj() const
{
	return new Operand(*this);
}

char Operand::dohvati_vrstu() const
{
	return 'D';
}

string Operand::dohvati_natpis() const
{
	return natpis;
}
