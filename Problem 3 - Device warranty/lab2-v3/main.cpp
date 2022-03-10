#include <iostream>
#include "Datum.h"
#include "Kvar.h"
#include "Garancija.h"
#include "Uredjaj.h"
#include "Klima.h"

using namespace std;

int main() {
	
	// Rad sa klasom: Datum
	Datum dat1{};
	Datum dat2{ 29,11,2020 };
	Datum dat3{ 29,10,2020 };
	Datum dat4{ 29,10,2021 };
	cout << dat1 << endl << dat3 << endl;
	cout << (dat1 < dat2) << endl;
	cout << dat1["dan"] << endl;
	cout << dat1["banana"] << endl << endl;

	// Rad sa klasom: Kvar
	Kvar k1{ "Pukla guma.",dat3,false };
	Kvar k2{ "Niko ne zna.",dat4, false };
	cout << k1 << endl;

	// Rad sa klasom: Garancija
	Garancija g1{ dat1, dat2 };
	g1.dodaj_kvar(k1);
	g1.dodaj_kvar(k2);
	cout << g1 << endl;

	// Rad sa klasom: Uredjaj
	Uredjaj u1{ "Aston Martin" };
	cout << u1;
	u1.postavi_garanciju(dat3, dat4);
	cout << u1.dohvati_garanciju();
	Uredjaj u2{ "Solarna susilica za ves" };
	cout << u2;
	u2.postavi_garanciju(&g1);
	cout << u2.dohvati_garanciju();
	cout << (u1 == u2) << endl << endl;

	// Rad sa klasom: Klima
	Klima kl1{ 100 , "Gorenje"};
	cout << kl1;
	kl1.postavi_garanciju(dat1);
	cout << kl1.dohvati_garanciju();

	return 0;
}