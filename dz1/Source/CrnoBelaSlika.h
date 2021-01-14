#ifndef _CrnoBelaSlika_h_
#define _CrnoBelaSlika_h_

#include "Slika.h"

using namespace std;

class CrnoBelaSlika :
	public Slika
{
private:


public:
	// Konstruktor
	CrnoBelaSlika(int sir = 0, int vis = 0, Vreme nas = { 0,0,0 });

	// Metode
	void postavi_piksel(const Piksel& p, const Pozicija& poz) override;
};

#endif