#include <cstdlib>
#include "Node.h"

Node::Node(char id, int time, int priority){
	this->_id = id;
	this->_time = time;
	this->_priority = priority;
	this->_next = NULL;
}

Node::~Node(){
	delete this->_next;
}

inline char Node::id(){
	return this->_id;
}

inline int Node::time(){
	return this->_time;
}

inline void Node::time(int time){
	this->_time = time;
}

inline int Node::priority(){
	return this->_priority;
}

inline void Node::priority(int priority){
	this->_priority = priority;
}

inline Node* Node::next(){
	return this->_next;
}

inline void Node::next(Node *next){
	this->_next = next;
}
