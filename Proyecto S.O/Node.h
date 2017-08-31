#ifndef __node
#define __node
class Node
{
	private:
		char _id;
		int _time;
		int _priority;
		Node *_next;

	public:
		Node(char, int, int);
		~Node();
		inline char id();
		inline int time();
		inline void time(int);
		inline int priority();
		inline void priority(int);
		inline Node* next();
		inline void next(Node *);
};
#endif