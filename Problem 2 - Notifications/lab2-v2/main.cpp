#include <iostream>
#include "Korisnik.h"
#include "Obavestenje.h"
#include "Objava.h"
#include "Lista_Obavestenja.h"

using namespace std;

int main() {

	// Rad sa klasom: Korisnik
	Korisnik k1{ "Dragan" };
	Korisnik k2{ "Boban" };

	// Rad sa klasom: Obavestenje
	Obavestenje o1{ &k1 };
	Obavestenje o2{ &k1 };
	Obavestenje o3{ &k2 };
	o3.procitaj();

	// Rad sa klasom: Objava
	Objava ob1{o1, "Prva objava!" };	// kopirajuci
	Objava ob2{ &k1, "Druga objava!" }; // standardni

	// Rad sa klasom: Lista_Obavestenja
	Lista_Obavestenja l1;
	l1 += o1; l1 += o2; l1 += o3;
	l1();
	cout << +l1 << endl;
	!l1;
	l1();
	cout << +l1 << endl;
	~l1;

	return 0;
}