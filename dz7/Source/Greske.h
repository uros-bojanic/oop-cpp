#pragma once

#include <exception>
using namespace std;

class GPraznaLista : public exception {
public:
	GPraznaLista() : exception("Greska: Lista je prazna.") {}
};
