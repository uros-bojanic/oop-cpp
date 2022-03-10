#ifndef _Galerija_h_
#define _Galerija_h_

#include "Slika.h"

class Galerija
{
protected:
	struct Node {
		const Slika* data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int n;
public:
	// Konstruktor
	Galerija();
	Galerija(const Galerija& g) = delete;

	// Destruktor
	~Galerija();

	// Metode
	int dohvati_broj_slika();
	int dohvati_velicinu_galerije();

	// Operatori
	virtual void operator+= (const Slika& s);
	Slika operator[] (int i);
	friend ostream& operator << (ostream & os, const Galerija & g);

};

#endif