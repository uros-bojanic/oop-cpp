#pragma once

#include <string>
#include <iostream>
using namespace std;

class Igrac
{
private:
	string ime;
	int vrednost;
public:
	// Konstruktori
	Igrac(string ime = "", int vrednost = 1000);
	// Getteri
	string dohvati_ime() const;
	int dohvati_vrednost() const;
	// Metode
	void povecaj_vrednost(int p);
	void smanji_vrednost(int p);
	// Operatori
	friend bool operator==(const Igrac& i1, const Igrac& i2);
	friend ostream& operator<<(ostream& os, const Igrac& i);
};

