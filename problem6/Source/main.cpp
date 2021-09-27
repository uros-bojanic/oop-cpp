#include <iostream>
#include "Tim.h"
#include "PrivilegovaniTim.h"
#include "Par.h"
#include "Mec.h"
using namespace std;

int main() {
	try {
		Igrac i1("Aki", 200);
		Igrac i2("Kiki", 300);
		Igrac i3("Uki", 400);
		Igrac i4("Jocki", 500);

		Tim t1("ER", 5);
		t1.prikljuci_igraca(1, &i1);
		t1.prikljuci_igraca(2, &i2);

		PrivilegovaniTim t2("SI", 5, 100);
		t2.prikljuci_igraca(1, &i3);
		t2.prikljuci_igraca(2, &i4);

		Mec m1(&t1, &t2);
		m1.odigraj_mec();
		cout << m1 << endl;
		cout << "Poeni: " << m1.dohvati_poene() << endl;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}