#include "Galerija.h"

Galerija::Galerija()
{
	head = tail = nullptr;
	n = 0;
}

Galerija::~Galerija()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		Node* prev = tmp;
		tmp = tmp->next;
		delete prev;
	}
}

int Galerija::dohvati_broj_slika()
{
	return n;
}

int Galerija::dohvati_velicinu_galerije()
{
	int vel = 0;
	Node* tmp = head;
	while (tmp != nullptr) {
		vel += tmp->data->dohvati_velicinu();
		tmp = tmp->next;
	}
	return vel;
}

void Galerija::operator+=(const Slika& s)
{
	Node* newNode = new Node;
	newNode->data = &s;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	n++;
}

Slika Galerija::operator[](int i)
{
	if (i >= n || i < 0) {
		exit(1);
	}
	int j = 0;
	Node* tmp = head;
	while (j != i) {
		tmp = tmp->next;
		j++;
	}
	return *(tmp->data);
}

ostream& operator<<(ostream& os, const Galerija& g)
{
	Galerija::Node* tmp = g.head;
	int i = 0;
	while (tmp != nullptr) {
		os << "Slika " << i++ + 1 << endl << *(tmp->data);
		tmp = tmp->next;
	}
	return os;
}
