#pragma once

#include "Tim.h"
#include "Par.h"
using namespace std;

class Mec
{
private:
	enum Ishod {NEODIGRANO, POBEDA_DOMACIN, NERESENO, POBEDA_GOST};
	Par<Tim> timovi;
	Ishod ishod;
	bool odigran;
public:
	// Konstruktori
	Mec(const Tim* t1, const Tim* t2);
	// Getteri
	const Par<Tim>& dohvati_timove() const;
	bool dohvati_odigran() const;
	// Metode
	void odigraj_mec();
	Par<int> dohvati_poene() const;
	// Operatori
	friend ostream& operator<<(ostream& os, const Mec& m);
};

