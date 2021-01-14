#pragma once

#include <iostream>
#include "Kvar.h"

using namespace std;

class Garancija
{
private:
	struct Node {
		Kvar* data;
		Node* next;
	};
	Node* head;
	Datum pocetak;
	Datum kraj;

public:
	// Konstruktori
	Garancija(Datum poc, Datum kr);

	// Destruktor
	~Garancija();

	// Getteri
	Datum get_pocetak();

	// Metode
	void dodaj_kvar(Kvar& kv);
	Kvar dohvati_poslednji_kvar();
	int dohvati_broj_kvarova();

	// Operatori
	friend ostream& operator<<(ostream& os, const Garancija& g);
};

