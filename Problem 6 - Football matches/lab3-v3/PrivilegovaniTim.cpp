#include "PrivilegovaniTim.h"
#include "Greske.h"

PrivilegovaniTim::PrivilegovaniTim(string naziv, int max_broj_igraca, int min_vrednost_igraca) : Tim(naziv, max_broj_igraca)
{
	this->min_vrednost_igraca = min_vrednost_igraca;
}

void PrivilegovaniTim::prikljuci_igraca(int pozicija, const Igrac* igrac)
{
	if (pozicija >= max_broj_igraca) throw GNeispravnaPozicija();
	if (igrac->dohvati_vrednost() < min_vrednost_igraca) throw GNedovoljnaVrednostIgraca();
	igraci[pozicija] = const_cast<Igrac*>(igrac);
}

void PrivilegovaniTim::pisi(ostream& os) const
{
	Tim::pisi(os);
	os << " (" << min_vrednost_igraca << ")";
}
