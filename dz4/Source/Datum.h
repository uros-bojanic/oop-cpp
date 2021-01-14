#pragma once

#include <iostream>
using namespace std;

class Datum
{
private:
	int dan, mes, god;
public:
	// Konstruktori
	Datum(int dan = 1, int mes = 1, int god = 2021);
	// Getteri
	int dohvati_dan() const;
	int dohvati_mes() const;
	int dohvati_god() const;
	// Operatori
	friend bool operator==(const Datum& d1, const Datum& d2);
	friend ostream& operator<<(ostream& os, const Datum& d);
};

