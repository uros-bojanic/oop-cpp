#pragma once

#include <iostream>
#include <string>

using namespace std;

class Datum
{
private:
	int dan;
	int mes;
	int god;

public:
	// Konstruktori
	Datum(int d = 30, int m = 11, int g = 2019);

	// Getteri
	int get_dan();
	int get_mes();
	int get_god();

	// Operatori
	int operator[](string s);
	friend bool operator<(Datum& dat1, Datum& dat2);
	friend ostream& operator<<(ostream& os, Datum& dat);
};

