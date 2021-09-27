#pragma once

#include <exception>
using namespace std;

class GNeispravanBrojZvezdica : public exception {
public:
	GNeispravanBrojZvezdica() : exception("Greska: Neispravan broj zvezdica.") {}
};

class GNeispravanDatum : public exception {
public:
	GNeispravanDatum() : exception("Greska: Neispravan datum.") {}
};

class GNeispravnaDestinacija : public exception {
public:
	GNeispravnaDestinacija() : exception("Greska: Neispravna destinacija.") {}
};

class GNemaSmestaja : public exception {
public:
	GNemaSmestaja() : exception("Greska: Nije zadat smestaj.") {}
};

class GNemaPrevoza : public exception {
public:
	GNemaPrevoza() : exception("Greska: Nije zadat prevoz.") {}
};
