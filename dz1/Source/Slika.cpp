#include "Slika.h"
#include <iomanip>

Slika::Slika(int sir, int vis, Vreme nas)
{
	sirina = sir;
	visina = vis;
	nastanak = nas;
	slika = new Piksel * [visina];
	for (int i = 0; i < visina; i++) {
		slika[i] = new Piksel[sirina];
		for (int j = 0; j < sirina; j++) {
			slika[i][j] = Piksel{ 0,0,0 };
		}
	}
}

Slika::Slika(const Slika& s)
{
	visina = s.visina;
	sirina = s.sirina;
	nastanak = s.nastanak;
	slika = new Piksel * [visina];
	for (int i = 0; i < visina; i++) {
		slika[i] = new Piksel[sirina];
		for (int j = 0; j < sirina; j++) {
			slika[i][j] = s.slika[i][j];
		}
	}
}

Slika::~Slika()
{
	for (int i = 0; i < visina; i++) {
		delete slika[i];
	}
	delete slika;
}

int Slika::dohvati_sirinu() const
{
	return sirina;
}

int Slika::dohvati_visinu() const
{
	return visina;
}

int Slika::dohvati_velicinu() const
{
	return 24 * visina * sirina;
}

Vreme Slika::dohvati_vreme_nastanka() const
{
	return nastanak;
}

void Slika::postavi_piksel(const Piksel& p, const Pozicija& poz)
{
	int vrs = poz.get_vrsta(); 
	int kol = poz.get_kolona();
	slika[vrs][kol] = p;
}

Piksel Slika::operator[](const Pozicija& poz)
{
	return slika[poz.get_vrsta()][poz.get_kolona()];
}

void Slika::operator=(const Slika& s)
{
	visina = s.visina;
	sirina = s.sirina;
	nastanak = s.nastanak;
	slika = new Piksel * [visina];
	for (int i = 0; i < visina; i++) {
		slika[i] = new Piksel[sirina];
		for (int j = 0; j < sirina; j++) {
			slika[i][j] = s.slika[i][j];
		}
	}
}

ostream& operator<<(ostream& os, const Slika& s)
{
	os << s.visina * s.sirina * 24 << endl;
	os << "Vreme nastanka: " << s.nastanak;
	for (int i = 0; i < s.visina; i++) {
		for (int j = 0; j < s.sirina; j++) {
			os << s.slika[i][j] << " ";
		}
		os << endl;
	}
	return os << endl;
}
