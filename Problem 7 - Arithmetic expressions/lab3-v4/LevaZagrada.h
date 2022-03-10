#pragma once
#include "Element.h"
class LevaZagrada :
	public Element
{
public:
	// Konstruktor
	LevaZagrada();
	// Metode
	LevaZagrada* polimorfno_kopiraj() const override;
	char dohvati_vrstu() const override;
	string dohvati_natpis() const override;
};

