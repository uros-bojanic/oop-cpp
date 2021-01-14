#pragma once

#include <iostream>
using namespace std;

class Element
{
public:
	// Metode
	virtual Element* polimorfno_kopiraj() const = 0;
	virtual char dohvati_vrstu() const = 0;
	virtual string dohvati_natpis() const = 0;
	// Operatori
	friend ostream& operator<<(ostream& os, const Element& e);
};

