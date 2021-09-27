#include <iostream>
#include "Lista.h"
#include "Operand.h"
#include "BinarniOperator.h"
#include "Sabiranje.h"
#include "LevaZagrada.h"
#include "DesnaZagrada.h"
#include "Izraz.h"
#include "GeneratorPostfiksa.h"
using namespace std;

int main() {
	try {
		Operand a("a");
		Operand b("b");
		Sabiranje s;
		LevaZagrada l;
		DesnaZagrada d;

		Izraz i1;
		i1 += a;
		i1 += s;
		i1 += l;
		i1 += l;
		i1 += a;
		i1 += s;
		i1 += b;
		i1 += d;
		i1 += s;
		i1 += b;
		i1 += d;
		cout << "Infiks:   " << i1 << endl;
		Izraz i1_postfiksno = (*GeneratorPostfiksa::napravi_generator())(i1);
		cout << "Postfiks: " << i1_postfiksno << endl;

		Izraz i2;
		i2 += a;
		i2 += s;
		i2 += b;
		i2 += s;
		i2 += a;
		i2 += s;
		i2 += b;
		cout << endl << "Infiks:   " << i2 << endl;
		Izraz i2_postfiksno = (*GeneratorPostfiksa::napravi_generator())(i2);
		cout << "Postfiks: " << i2_postfiksno;
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	return 0;
}