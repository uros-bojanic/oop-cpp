#pragma once

#include <exception>
using namespace std;

class GNeispravnaPozicija : public exception {
public:
	GNeispravnaPozicija() : exception("Greska: Neispravna pozicija igraca u timu.") {}
};

class GNedovoljnaVrednostIgraca : public exception {
public:
	GNedovoljnaVrednostIgraca() : exception("Greska: Vrednost igraca je suvise mala za prikljucivanje timu.") {}
};

class GMecNijeOdigran : public exception {
public:
	GMecNijeOdigran() : exception("Greska: Mec nije odigran.") {}
};

