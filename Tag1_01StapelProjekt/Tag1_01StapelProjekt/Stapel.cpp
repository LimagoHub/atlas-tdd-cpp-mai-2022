#include "Stapel.h"
#include "StapelException.h"

Stapel::Stapel() :index(0)
{
}

void Stapel::push(int value)
{
	if (is_full()) throw StapelException{ "Overflow" };
	data[index++] = value;
}

int Stapel::pop()
{
	if (is_empty()) throw StapelException{ "Underflow" };
	return data[--index];
}
bool Stapel::is_empty() const
{
	return  index == 0;
}
bool Stapel::is_full() const
{
	return index == 10;
}