#include "SivaSlika.h"

SivaSlika::SivaSlika(int sir, int vis, Vreme nas) : Slika(sir, vis,nas)
{
}

void SivaSlika::postavi_piksel(const Piksel& p, const Pozicija& poz)
{
	int vrs = poz.get_vrsta();
	int kol = poz.get_kolona();
	
	int RGB = (p.get_R() + p.get_G() + p.get_B()) / 3;

	slika[vrs][kol] = Piksel{ RGB,RGB,RGB };
}

SivaSlika::operator CrnoBelaSlika()
{
	CrnoBelaSlika cbs{sirina, visina, nastanak};
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			int R = slika[i][j].get_R() >= 128 ? 255 : 0;
			int G = slika[i][j].get_G() >= 128 ? 255 : 0;
			int B = slika[i][j].get_B() >= 128 ? 255 : 0;
			cbs.postavi_piksel(Piksel{ R,G,B }, Pozicija{ i,j });
		}
	}
	return cbs;
}
