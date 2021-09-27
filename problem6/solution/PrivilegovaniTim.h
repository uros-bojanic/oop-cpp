#pragma once

#include "Tim.h"
using namespace std;

class PrivilegovaniTim :
	public Tim
{
private:
	int min_vrednost_igraca;
public:
	// Konstruktor
	PrivilegovaniTim(string naziv = "", int max_broj_igraca = 0, int min_vrednost_igraca = 0);
	// Metode
	void prikljuci_igraca(int pozicija, const Igrac* igrac) override;
	void pisi(ostream& os) const override;
};

