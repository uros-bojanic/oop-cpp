#pragma once
#include "Element.h"
class DesnaZagrada :
	public Element
{
public:
	// Konstruktor
	DesnaZagrada();
	// Metode
	DesnaZagrada* polimorfno_kopiraj() const override;
	char dohvati_vrstu() const override;
	string dohvati_natpis() const override;
};

