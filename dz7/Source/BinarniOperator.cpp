#include "BinarniOperator.h"

BinarniOperator::BinarniOperator(int prioritet) : Element()
{
	this->prioritet = prioritet;
}

int BinarniOperator::dohvati_prioritet() const
{
	return prioritet;
}

char BinarniOperator::dohvati_vrstu() const
{
	return 'O';
}

bool operator>(const BinarniOperator& b1, const BinarniOperator& b2)
{
	return (b1.prioritet > b2.prioritet);
}
