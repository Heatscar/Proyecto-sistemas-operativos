#include <cstdio>
#include "Round_Robin.h"

void Round_Robin::insert(char id, int time, int priority){
	Node *new_node = new Node(id, time, priority);
	if(empty()){
		this->initial = new_node;
		this->final = new_node;
	}

	else{
		final->next(new_node);
		final = final->next();
	}

	this->_size ++;
	this->_time += time;
	this->_quantum = this->_time / this->_size;
}

void Round_Robin::insert(Node *unfinished){
	if(unfinished != final){
		final->next(unfinished);
		final = unfinished;
	}
}

void Round_Robin::pop(){
	this->_time += initial->time() >= quantum() ? quantum() : initial->time();
	Node *aux = this->initial;
	aux->time(aux->time() - quantum());
	this->initial = this->initial->next();
	aux->next(NULL);
	if(aux->time() > 0) insert(aux);
	else{
	    printf("Termina %c\n", aux->id());
		delete aux;
		this->_size --;
	}
}

inline int Round_Robin::quantum(){
	return this->_quantum;
}
