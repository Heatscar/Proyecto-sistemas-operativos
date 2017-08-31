#ifndef __priority
#define __priority

#include "Fifo.h"

class Priority : public Fifo
{
	private:
		int _quantum;
		void insert(Node*);

	public:
		Priority() : Fifo() {};
		virtual void insert(char, int, int);
		virtual void pop();
		inline int quantum();
};
#endif
