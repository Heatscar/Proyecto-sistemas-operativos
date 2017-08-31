#ifndef __round_robin
#define __round_robin

#include "Fifo.h"

class Round_Robin : public Fifo
{
	private:
		int _quantum;
		void insert(Node*);

	public:
		Round_Robin() : Fifo(){ this->_quantum = 0;}
		virtual void insert(char, int, int);
		virtual void pop();
		inline int quantum();
};
#endif
