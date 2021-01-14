#include "NutritivnaVrednost.h"

NutritivnaVrednost::NutritivnaVrednost(int ugljeni_hidrati, int masti, int proteini)
{
	this->ugljeni_hidrati = ugljeni_hidrati;
	this->masti = masti;
	this->proteini = proteini;
}

int NutritivnaVrednost::dohvati_ugljeni_hidrati() const
{
	return ugljeni_hidrati;
}

int NutritivnaVrednost::dohvati_masti() const
{
	return masti;
}

int NutritivnaVrednost::dohvati_proteini() const
{
	return proteini;
}

int NutritivnaVrednost::ukupan_broj_kalorija() const
{
	return 4*(ugljeni_hidrati + proteini) + 9*masti;
}

NutritivnaVrednost& operator+(const NutritivnaVrednost& n1, const NutritivnaVrednost& n2)
{
	NutritivnaVrednost n3(n1.ugljeni_hidrati + n2.ugljeni_hidrati, n1.masti + n2.masti, n1.proteini + n2.proteini);
	return n3;
}

ostream& operator<<(ostream& os, const NutritivnaVrednost& n)
{
	return os << "[uh: " << n.ugljeni_hidrati << ", " << "ma: " << n.masti << ", " << "pr: " << n.proteini << "]";
}