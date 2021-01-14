#ifndef _Vreme_h_
#define _Vreme_h_

#include <iostream>

using namespace std;

class Vreme
{
private:
	int cas, min, sek;
public:
	// Konstruktor
	Vreme(int c = 0, int m = 0, int s = 0);

	// Operatori
	friend bool operator>(const Vreme& v1, const Vreme& v2);
	friend ostream& operator<<(ostream& os, const Vreme& v);
};

#endif