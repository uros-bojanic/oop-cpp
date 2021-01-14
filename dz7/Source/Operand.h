#pragma once
#include "Element.h"
class Operand :
	public Element
{
private:
	string natpis;
public:
	// Konstruktor
	Operand(string natpis = "");
	// Metode
	Operand* polimorfno_kopiraj() const override;
	char dohvati_vrstu() const override;
	string dohvati_natpis() const override;
};

