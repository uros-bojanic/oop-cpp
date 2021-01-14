#include "Lista_Obavestenja.h"

Lista_Obavestenja::Lista_Obavestenja()
{
	head = nullptr;
}

Lista_Obavestenja& Lista_Obavestenja::operator+=(Obavestenje& o)
{
	Node* tmp = new Node;
	tmp->data = &o;
	tmp->next = this->head;
	this->head = tmp;
	return *this;
}

void Lista_Obavestenja::operator()()
{
	Lista_Obavestenja::Node* tmp = this->head;
	while (tmp != nullptr) {
		if (tmp->data->get_procitano() == false) {
			cout << *(tmp->data);
		}
		tmp = tmp->next;
	}
}

int Lista_Obavestenja::operator+()
{
	int count = 0;
	Node* tmp = head;
	while (tmp != nullptr) {
		if (tmp->data->get_procitano() == false) {
			count++;
		}
		tmp = tmp->next;
	}
	return count;
}

void Lista_Obavestenja::operator!()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		if (tmp->data->get_procitano() == false) {
			tmp->data->procitaj();
		}
		tmp = tmp->next;
	}
}

void Lista_Obavestenja::operator~()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		Node* succ = tmp->next;
		free(tmp);
		tmp = succ;
	}
	head = tmp;
}
