#include "Tim.h"
#include "Greske.h"

Tim::Tim(string naziv, int max_broj_igraca)
{
	this->naziv = naziv;
	this->max_broj_igraca = max_broj_igraca;
	igraci = new Igrac * [max_broj_igraca];
	for (int i = 0; i < max_broj_igraca; i++)
		igraci[i] = nullptr;
}

Tim::Tim(const Tim& t)
{
	kopiraj(t);
}

Tim::Tim(Tim&& t)
{
	premesti(t);
}

Tim& Tim::operator=(const Tim& t)
{
	if (this != &t) {
		isprazni();
		kopiraj(t);
	}
	return *this;
}

Tim& Tim::operator=(Tim&& t)
{
	if (this != &t) {
		isprazni();
		premesti(t);
	}
	return *this;
}

Tim::~Tim()
{
	isprazni();
}

void Tim::kopiraj(const Tim& l)
{
	naziv = l.naziv;
	max_broj_igraca = l.max_broj_igraca;
	igraci = new Igrac * [max_broj_igraca];
	for (int i = 0; i < max_broj_igraca; i++)
		igraci[i] = l.igraci[i];
}

void Tim::premesti(Tim& l)
{
	naziv = l.naziv;
	max_broj_igraca = l.max_broj_igraca;
	igraci = l.igraci;
	l.igraci = nullptr;
}

void Tim::isprazni()
{
	delete[] igraci;
}

void Tim::prikljuci_igraca(int pozicija, const Igrac* igrac)
{
	if (pozicija >= max_broj_igraca) throw GNeispravnaPozicija();
	igraci[pozicija] = const_cast<Igrac*>(igrac);
}

int Tim::dohvati_broj_igraca() const
{
	int br = 0;
	for (int i = 0; i < max_broj_igraca; i++)
		if (igraci[i] != nullptr)
			br++;
	return br;
}

int Tim::dohvati_vrednost_tima() const
{
	int s = 0;
	for (int i = 0; i < max_broj_igraca; i++)
		if (igraci[i] != nullptr)
			s += igraci[i]->dohvati_vrednost();
	return s/dohvati_broj_igraca();
}

void Tim::azuriraj_vrednost_igraca(int p)
{
	for (int i = 0; i < max_broj_igraca; i++)
		if (igraci[i] != nullptr)
			if (p > 0)
				igraci[i]->povecaj_vrednost(p);
			else
				igraci[i]->smanji_vrednost(-p);
}

void Tim::pisi(ostream& os) const
{
	os << naziv << "[";
	for (int i = 0; i < max_broj_igraca; i++)
		if (igraci[i] != nullptr)
			os << *(igraci[i]) << ",";
	os << "]";
}

Igrac& Tim::operator[](int i) const
{
	return *(igraci[i]);
}

bool operator==(const Tim& t1, const Tim& t2)
{
	bool isti = true;
	if (t1.naziv != t2.naziv || t1.max_broj_igraca != t2.max_broj_igraca)
		isti = false;
	for (int i = 0; i < t1.max_broj_igraca; i++)
		if (t1.igraci[i] != t2.igraci[i])
			isti = false;
	return isti;
}

ostream& operator<<(ostream& os, const Tim& t)
{
	t.pisi(os);
	return os;
}
