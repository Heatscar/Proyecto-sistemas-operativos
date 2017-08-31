#ifndef __fifo
#define __fifo

#include "Node.cpp"

class Fifo
{
	protected:
		Node *initial;
		Node *final;
		int _size;
		int _time;

	public:
		Fifo();
		~Fifo();
		void insert(char, int, int);
		void pop();
		void print_full();
		inline bool empty();
		inline int size();
		inline int time();
		inline void time(int);
};
#endif
