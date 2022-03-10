#pragma once

#include <iostream>
using namespace std;

class Destinacija
{
private:
	string naziv;
	string opis;
	unsigned int prosecna_ocena, broj_ocena;
public:
	// Konstruktori
	Destinacija(string naziv = "", string opis = "");
	// Getteri
	string dohvati_naziv() const;
	string dohvati_opis() const;
	int dohvati_prosecna_ocena() const;
	// Metode
	void oceni(unsigned int ocena);
	// Operatori
	friend bool operator>(const Destinacija& d1, const Destinacija& d2);
	friend ostream& operator<<(ostream& os, const Destinacija& d);
};

