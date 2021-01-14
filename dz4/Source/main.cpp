#include <iostream>
#include "BankovniRacun.h"
#include "DinarskiRacun.h"
using namespace std;

int main() {
	try {
		Datum d1(6, 3, 2000);
		Osoba o1("Uros", "1234", d1);

		DinarskiRacun din1(&o1, 99);
		din1 += 250;
		DinarskiRacun din2(&o1, 77);
		if(din1.prebaci(100, din2)) cout << "Prenos uspesan!" << endl;

		cout << din1 << endl;
		cout << din2 << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}