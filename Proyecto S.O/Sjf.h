#ifndef __sjf
#define __sjf

#include "Fifo.h"

class Sjf : public Fifo
{
	public:
		Sjf() : Fifo() {};
		virtual void insert(char, int, int);
};
#endif
