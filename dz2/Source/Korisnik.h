#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Korisnik
{
private:
	string ime;

public:
	// Konstruktori
	Korisnik(string ime) : ime(ime) {}

	// Getteri
	string get_ime() const;

	// Operatori
	friend ostream& operator<<(ostream& os, const Korisnik& k);

	// Prijatelji
	friend class Obavestenje;
};

