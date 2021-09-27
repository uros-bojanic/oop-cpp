#pragma once

#include <iostream>
using namespace std;

class NutritivnaVrednost
{
private:
	int ugljeni_hidrati, masti, proteini;
public:
	// Konstruktori
	NutritivnaVrednost(int ugljeni_hidrati = 0, int masti = 0, int proteini = 0);
	// Getteri
	int dohvati_ugljeni_hidrati() const;
	int dohvati_masti() const;
	int dohvati_proteini() const;
	// Metode
	int ukupan_broj_kalorija() const;
	// Operatori
	friend NutritivnaVrednost& operator+(const NutritivnaVrednost& n1, const NutritivnaVrednost& n2);
	friend ostream& operator<<(ostream& os, const NutritivnaVrednost& n);
};

