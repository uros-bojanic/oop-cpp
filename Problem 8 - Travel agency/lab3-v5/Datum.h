#pragma once

#include <iostream>
using namespace std;

class Datum
{
private:
	int dan, mes, god;
public:
	// Konstruktori
	Datum(int dan, int mes, int god);
	// Getteri
	int dohvati_dan() const;
	int dohvati_mes() const;
	int dohvati_god() const;
	// Operatori
	friend int operator-(const Datum& d1, const Datum& d2);
	friend ostream& operator<<(ostream& os, const Datum& d);
};

