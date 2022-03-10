#include "CrnoBelaSlika.h"

CrnoBelaSlika::CrnoBelaSlika(int sir, int vis, Vreme nas) : Slika(sir,vis,nas)
{
}

void CrnoBelaSlika::postavi_piksel(const Piksel& p, const Pozicija& poz)
{
	int vrs = poz.get_vrsta();
	int kol = poz.get_kolona();

	int R = p.get_R() >= 128 ? 255 : 0;
	int G = p.get_G() >= 128 ? 255 : 0;
	int B = p.get_B() >= 128 ? 255 : 0;

	slika[vrs][kol] = Piksel{ R,G,B };
}
