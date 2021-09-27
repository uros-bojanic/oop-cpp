#pragma once

#include <iostream>
#include "NutritivnaVrednost.h"
using namespace std;

class Namirnica
{
private:
	string naziv;
	NutritivnaVrednost nutritivna_vrednost;
	bool posno;
public:
	// Konstruktori
	Namirnica(string naziv = "", NutritivnaVrednost nutritivna_vrednost = NutritivnaVrednost(), bool posno = false);
	// Getteri
	string dohvati_naziv() const;
	NutritivnaVrednost dohvati_nutritivna_vrednost() const;
	bool dohvati_posno() const;
	// Operatori
	friend bool operator==(const Namirnica& n1, const Namirnica& n2);
	friend ostream& operator<<(ostream& os, const Namirnica& n);
};

