#pragma once

#include <exception>
using namespace std;

class GNePostojiElement : public exception
{
public:
	GNePostojiElement() : exception("Greska: Tekuci element ne postoji.") {}
};
