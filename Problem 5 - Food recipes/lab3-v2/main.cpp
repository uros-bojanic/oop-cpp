#include <iostream>
#include "NutritivnaVrednost.h"
#include "Namirnica.h"
#include "Sastojak.h"
#include "Lista.h"
using namespace std;

int main() {
	try {
		NutritivnaVrednost n1(10, 20, 20);
		NutritivnaVrednost n2(15, 15, 15);
		NutritivnaVrednost n3 = n1 + n2;

		Namirnica hleb("hleb", n1, true);
		Namirnica mleko("mleko", n2, false);
		Namirnica ulje("ulje", n3, true);

		Sastojak s1(hleb, 500);
		Sastojak s2(mleko, 300);
		Sastojak s3(ulje, 100);

		Lista<Sastojak> lista;
		lista.dodaj_na_kraj(s1).dodaj_na_kraj(s2).dodaj_na_kraj(s3).postavi_tekuci_na_prvi();
		lista.pomeri_tekuci_na_sledeci().izbaci_tekuci().postavi_tekuci_na_prvi();
		while (lista.postoji_tekuci()) {
			cout << lista.dohvati_tekuci_element() << endl;
			lista.pomeri_tekuci_na_sledeci();
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}