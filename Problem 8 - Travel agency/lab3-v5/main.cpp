#include <iostream>
#include "Destinacija.h"
#include "Smestaj.h"
#include "Prevoz.h"
#include "Datum.h"
#include "Aranzman.h"
using namespace std;

int main() {
	try {
		Destinacija d1("Maldivi", "prelepo");
		d1.oceni(5);
		d1.oceni(3);
		d1.oceni(4);

		Smestaj s1(d1, Smestaj::APARTMAN, "Dva goluba bela", 3, 10.5);
		Prevoz p1(d1, 2.5);
		Datum dat1(12, 1, 2021);
		Datum dat2(19, 1, 2021);

		Aranzman a(d1, dat1, dat2);
		a.postavi_prevoz(p1);
		a.postavi_smestaj(s1);
		cout << a << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}