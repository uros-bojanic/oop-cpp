#pragma once

#include "Datum.h"

using namespace std;

class Kvar
{
private:
	string opis;
	Datum datum;
	bool otklonjenost;

public:
	// Konstruktori
	Kvar(string s = "", Datum d = Datum(), bool o = false);

	// Getteri
	string get_opis();
	Datum& get_datum();
	bool get_otklonjenost();

	// Setteri
	void set_otklonjenost(bool b);

	// Operatori
	friend ostream& operator<<(ostream& os, Kvar& kv);
};

