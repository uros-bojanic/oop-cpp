#include "SarenaSlika.h"

SarenaSlika::SarenaSlika(int sir, int vis, Vreme nas) : Slika(sir, vis,nas)
{
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			bool je_sarena = true;
			do {
				slika[i][j] = Piksel{ rand() % 255, rand() % 255, rand() % 255 };

				if (i > 0 && slika[i][j] == slika[i - 1][j]) {
					je_sarena = false;
				}
				if (i < visina - 1 && slika[i][j] == slika[i + 1][j]) {
					je_sarena = false;
				}
				if (j > 0 && slika[i][j] == slika[i][j - 1]) {
					je_sarena = false;
				}
				if (j < sirina - 1 && slika[i][j] == slika[i][j + 1]) {
					je_sarena = false;
				}
			} while (!je_sarena);
			
		}
	}
}

SarenaSlika::SarenaSlika(Slika& s1, Slika& s2) : Slika(s1.dohvati_sirinu(), s1.dohvati_visinu(), (s1.dohvati_vreme_nastanka() > s2.dohvati_vreme_nastanka()) ? s1.dohvati_vreme_nastanka() : s2.dohvati_vreme_nastanka())
{
	if (s1.dohvati_visinu() == s2.dohvati_visinu() && s1.dohvati_sirinu() == s2.dohvati_sirinu()) {
		for (int i = 0; i < visina; i++) {
			for (int j = 0; j < sirina; j++) {
				int R = (s1[Pozicija{ i,j }].get_R() + s2[Pozicija{ i,j }].get_R()) / 2;
				int G = (s1[Pozicija{ i,j }].get_G() + s2[Pozicija{ i,j }].get_G()) / 2;
				int B = (s1[Pozicija{ i,j }].get_B() + s2[Pozicija{ i,j }].get_B()) / 2;
				slika[i][j] = Piksel{ R,G,B };
			}
		}
	}
}

void SarenaSlika::postavi_piksel(const Piksel& p, const Pozicija& poz)
{
	int vrs = poz.get_vrsta();
	int kol = poz.get_kolona();

	bool je_sarena = true;
	if (vrs > 0 && (p == slika[vrs - 1][kol])) {
		je_sarena = false;
	}
	if (vrs < visina - 1 && (p == slika[vrs + 1][kol])) {
		je_sarena = false;
	}
	if (kol > 0 && (p == slika[vrs][kol - 1])) {
		je_sarena = false;
	}
	if (kol < sirina - 1 && (p == slika[vrs][kol + 1])) {
		je_sarena = false;
	}

	if (je_sarena) {
		slika[vrs][kol] = p;
	}
}
