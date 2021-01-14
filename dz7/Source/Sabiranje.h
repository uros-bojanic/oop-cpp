#pragma once
#include "BinarniOperator.h"
class Sabiranje :
	public BinarniOperator
{
public:
	// Konstruktor
	Sabiranje();
	// Metode
	Sabiranje* polimorfno_kopiraj() const override;
	string dohvati_natpis() const override;
};
