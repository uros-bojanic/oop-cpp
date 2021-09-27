#ifndef _SarenaSlika_h_
#define _SarenaSlika_h_

#include "Slika.h"

class SarenaSlika :
	public Slika
{
public:
	// Konstruktori
	SarenaSlika(int sir = 0, int vis = 0, Vreme nas = { 0,0,0 });
	SarenaSlika(Slika& s1, Slika& s2);

	// Metode
	void postavi_piksel(const Piksel& p, const Pozicija& poz) override;
};

#endif