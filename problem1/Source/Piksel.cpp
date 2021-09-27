#include "Piksel.h"
#include <iomanip>

Piksel::Piksel(int r, int g, int b)
{
	R = r;
	G = g;
	B = b;
}

int Piksel::get_R() const
{
	return R;
}

int Piksel::get_G() const
{
	return G;
}

int Piksel::get_B() const
{
	return B;
}

Piksel& operator+(const Piksel& p1, const Piksel& p2)
{
	int r = (p1.R + p2.R) / 2;
	int g = (p1.G + p2.G) / 2;
	int b = (p1.B + p2.B) / 2;
	return *(new Piksel { r, g, b });
}

bool operator==(const Piksel& p1, const Piksel& p2)
{
	return (p1.R == p2.R && p1.G == p2.G && p1.B == p2.B);
}

ostream& operator<<(ostream& os, const Piksel& p)
{
	os << "(";
	os << setfill('0') << setw(3) << p.R;
	os << ",";
	os << setfill('0') << setw(3) << p.G;
	os << ",";
	os << setfill('0') << setw(3) << p.B;
	os << ")";
	return os;
}
