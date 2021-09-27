#include "GalerijaUredjena.h"

GalerijaUredjena::GalerijaUredjena() : Galerija()
{
}

void GalerijaUredjena::operator+=(const Slika& s)
{
	Node* tmp = head;
	Node* newNode = new Node;
	newNode->data = &s;
	if (head == nullptr) {
		newNode->next = head;
		head = tail = newNode;
	}
	else if (head->data->dohvati_vreme_nastanka() > s.dohvati_vreme_nastanka()) {
		newNode->next = head;
		head = newNode;
	}
	else {
		while (tmp->next != nullptr) {
			if (tmp->next->data->dohvati_vreme_nastanka() > s.dohvati_vreme_nastanka()) {
				break;
			}
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	n++;
}
