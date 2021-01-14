#pragma once

#include <exception>
using namespace std;

class GPogresanDatum : public exception
{
public:
	GPogresanDatum() : exception("Greska: Pogresno unet datum.") {}
};

class GIznosNegativan : public exception
{
public:
	GIznosNegativan() : exception("Greska: Iznos za prenos je negativan.") {}
};
