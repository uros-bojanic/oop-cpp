#pragma once
#include "Element.h"
class BinarniOperator :
	public Element
{
private:
	int prioritet;
public:
	// Konstruktor
	BinarniOperator(int prioritet = 0);
	// Metode
	int dohvati_prioritet() const;
	char dohvati_vrstu() const override;
	string dohvati_natpis() const override = 0;
	// Operatori
	friend bool operator>(const BinarniOperator& b1, const BinarniOperator& b2);
};

