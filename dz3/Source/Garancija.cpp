#include "Garancija.h"

Garancija::Garancija(Datum poc, Datum kr)
{
	pocetak = poc;
	kraj = kr;
	head = nullptr;
}

Garancija::~Garancija()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		Node* prev = tmp;
		tmp = tmp->next;
		free(prev);
	}
}

Datum Garancija::get_pocetak()
{
	return pocetak;
}

void Garancija::dodaj_kvar(Kvar& kv)
{
	bool poslednji_otklonjenost = true;
	if (head != nullptr) {
		Kvar poslednji = *(head->data);
		poslednji_otklonjenost = poslednji.get_otklonjenost();
	}
	if ((pocetak < kv.get_datum()) && (kv.get_datum() < kraj) && poslednji_otklonjenost) {
		Node* tmp = new Node;
		tmp->data = &kv;
		tmp->next = head;
		head = tmp;
	}
	else {
		cout << "Kvar nije pokriven garancijiom." << endl;
	}
}

Kvar Garancija::dohvati_poslednji_kvar()
{
	return *(head->data);
}

int Garancija::dohvati_broj_kvarova()
{
	int brojac = 0;
	Node* tmp = head;
	while (tmp != nullptr) {
		brojac++;
		tmp = tmp->next;
	}
	return brojac;
}

ostream& operator<<(ostream& os, const Garancija& g)
{
	return os << g.pocetak << "-" << g.kraj << "-broj kvarova:" << g.dohvati_broj_kvarova() << endl;
}
