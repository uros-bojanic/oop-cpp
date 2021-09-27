#ifndef _Piksel_h_
#define _Piksel_h_

#include <iostream>

using namespace std;

class Piksel
{
private:
	int R, G, B;

public:
	// Konstruktori
	Piksel(int r = 0, int g = 0, int b = 0);

	// Getteri
	int get_R() const;
	int get_G() const;
	int get_B() const;

	// Operatori
	friend Piksel& operator+(const Piksel& p1, const Piksel& p2);
	friend bool operator==(const Piksel& p1, const Piksel& p2);
	friend ostream& operator<<(ostream& os, const Piksel& p);
};

#endif