#include <iostream>
#include "Piksel.h"
#include "Pozicija.h"
#include "Slika.h"
#include "CrnoBelaSlika.h"
#include "Vreme.h"
#include "SarenaSlika.h"
#include "SivaSlika.h"
#include "Galerija.h"
#include "GalerijaUredjena.h"

using namespace std;

int main() {
	Slika s1{ 2,2,Vreme{17,15,00} };
	s1.postavi_piksel(Piksel{ 200,200,200 }, Pozicija{ 0,0 });
	s1.postavi_piksel(Piksel{ 200,200,200 }, Pozicija{ 1,1 });
	Slika s2{ 2,2,Vreme{19,25,00} };
	s2.postavi_piksel(Piksel{ 100,100,100 }, Pozicija{ 0,1 });
	s2.postavi_piksel(Piksel{ 100,100,100 }, Pozicija{ 1,0 });
	
	CrnoBelaSlika cbs{ 2,2,Vreme{19,30,00} };
	cbs.postavi_piksel(Piksel{ 200,200,200 }, Pozicija{ 0,0 });
	cbs.postavi_piksel(Piksel{ 100,100,100 }, Pozicija{ 1,1 });
	
	SarenaSlika sas{ 2,2,Vreme{19,45,00} };

	SivaSlika sis{ 2,2,Vreme{14,20,00} };
	sis.postavi_piksel(Piksel{ 260,200,220 }, Pozicija{ 0,0 }); cout << sis;

	CrnoBelaSlika cbs2 = (CrnoBelaSlika)sis; cout << cbs2;

	GalerijaUredjena gu;
	gu += s1;
	gu += s2;
	gu += cbs;
	gu += sas;
	gu += sis;
	gu += cbs2;
	cout << "Broj slika u galeriji: " << gu.dohvati_broj_slika() << endl;
	cout << "Velicina svih slika u galeriji (u bitovima): " << gu.dohvati_velicinu_galerije() << endl;
	cout << endl << gu;

	SarenaSlika ss2{ s1, sas };
	cout << "Sarena slika 2: " << ss2;

	return 0;
}