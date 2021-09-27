#pragma once

#include <iostream>
#include "Destinacija.h"
using namespace std;

class Smestaj
{
public:
	enum Tip { HOTEL, APARTMAN };
private:
	Destinacija destinacija;
	Tip tip;
	string naziv;
	int broj_zvezdica;
	double cena_po_danu;
public:
	// Konstruktor
	Smestaj(const Destinacija& destinacija = Destinacija(), Tip tip = HOTEL, string naziv = "", int broj_zvezdica = 1, double cena_po_danu = 0.0);
	// Getteri
	const Destinacija& dohvati_destinacija() const;
	Tip dohvati_tip() const;
	string dohvati_naziv() const;
	int dohvati_broj_zvezdica() const;
	double dohvati_cena_po_danu() const;
	// Operator
	friend ostream& operator<<(ostream& os, const Smestaj& s);
};

