#pragma once

#include "Izraz.h"
using namespace std;

class GeneratorPostfiksa
{
private:
	static GeneratorPostfiksa* generator_postfiksa;
	// Konstruktor
	GeneratorPostfiksa();
public:
	// Staticka metoda za instanciranje
	static GeneratorPostfiksa* napravi_generator();
	GeneratorPostfiksa(const GeneratorPostfiksa& g) = delete;
	GeneratorPostfiksa& operator=(const GeneratorPostfiksa& g) = delete;
	// Metode
	Izraz& operator()(const Izraz& i);
};

