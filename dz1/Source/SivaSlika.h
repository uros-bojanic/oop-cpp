#ifndef _SivaSlika_h_
#define _SivaSlika_h_

#include "Slika.h"
#include "CrnoBelaSlika.h"

class SivaSlika :
	public Slika
{
public:
	// Konstruktor
	SivaSlika(int sir = 0, int vis = 0, Vreme nas = { 0,0,0 });

	// Metode
	void postavi_piksel(const Piksel& p, const Pozicija& poz) override;

	// Operatori
	operator CrnoBelaSlika();
};

#endif