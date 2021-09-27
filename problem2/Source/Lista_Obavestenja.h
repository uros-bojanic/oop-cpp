#pragma once

#include "Obavestenje.h"

class Lista_Obavestenja
{
private:
	struct Node {
		Obavestenje* data; // da li je ovo katastrofalno lose ili ne? recimo ne :)
		Node* next;
	};
	Node* head;

public:
	// Konstruktori
	Lista_Obavestenja();

	// Operatori
	Lista_Obavestenja& operator+=(Obavestenje& o);
	void operator()();
	int operator+();
	void operator!();
	void operator~();
	// dodati operator[]
};

