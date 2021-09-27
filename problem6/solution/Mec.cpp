#include "Mec.h"
#include "Greske.h"

Mec::Mec(const Tim* t1, const Tim* t2)
{
	timovi = Par<Tim>(t1, t2);
	ishod = NEODIGRANO;
	odigran = false;
}

const Par<Tim>& Mec::dohvati_timove() const
{
	return timovi;
}

bool Mec::dohvati_odigran() const
{
	return odigran;
}

void Mec::odigraj_mec()
{
	if (timovi.dohvati_prvi().dohvati_vrednost_tima() > timovi.dohvati_drugi().dohvati_vrednost_tima())
		ishod = POBEDA_DOMACIN;
	else if (timovi.dohvati_prvi().dohvati_vrednost_tima() == timovi.dohvati_drugi().dohvati_vrednost_tima())
		ishod = NERESENO;
	else
		ishod = POBEDA_GOST;
	switch (ishod)
	{
	case Mec::POBEDA_DOMACIN:
		timovi.dohvati_prvi().azuriraj_vrednost_igraca(10);
		timovi.dohvati_drugi().azuriraj_vrednost_igraca(-10);
		break;
	case Mec::POBEDA_GOST:
		timovi.dohvati_prvi().azuriraj_vrednost_igraca(-10);
		timovi.dohvati_drugi().azuriraj_vrednost_igraca(10);
		break;
	default:
		break;
	}
	odigran = true;
}

Par<int> Mec::dohvati_poene() const
{
	if (odigran == false) throw GMecNijeOdigran();
	int *pa = nullptr, *pb = nullptr;
	switch (ishod)
	{
	case Mec::POBEDA_DOMACIN:
		pa = new int(3);
		pb = new int(0);
		break;
	case Mec::NERESENO:
		pa = new int(1);
		pb = new int(1);
		break;
	case Mec::POBEDA_GOST:
		pa = new int(0);
		pb = new int(3);
		break;
	default:
		break;
	}
	return Par<int>(pa, pb);
}

ostream& operator<<(ostream& os, const Mec& m)
{
	os << m.timovi;
	if (m.odigran)
		switch (m.ishod)
		{
		case Mec::POBEDA_DOMACIN:
			os << ", POBEDIO DOMACIN"; break;
		case Mec::NERESENO:
			os << ", NERESENO"; break;
		case Mec::POBEDA_GOST:
			os << ", POBEDIO GOST"; break;
		default:
			break;
		}
	return os;
}
