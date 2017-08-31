#include <cstdlib>
#include "Fifo.h"

Fifo::Fifo(){
	this->initial = NULL;
	this->final = NULL;
	this->_size = 0;
	this->_time = 0;
}

Fifo::~Fifo(){
	delete this->initial;
	delete this->final;
}

void Fifo::insert(char id, int time, int priority){
	Node *new_node = new Node(id, time, priority);

	if(empty()){
		this->initial = new_node;
		this->final = new_node;
	}

	else{
		this->final->next(new_node);
		this->final = new_node;
	}

	this->_size ++;
	this->_time = 0;
}



void Fifo::pop(){
	this->_time += this->initial->time();
	Node *aux = this->initial;
	this->initial = this->initial->next();
	aux->next(NULL);
	
	    printf("Termina %c\n", aux->id());
		delete aux;
		this->_size --;
}

void Fifo::print_full(){
	Node *aux = this->initial;
	while(aux){
		printf("TR%c = %i\n", aux->id(), aux->time());
		aux = aux->next();
	}
}

inline bool Fifo::empty(){
	return !this->initial ? true : false;
}

inline int Fifo::size(){
	return this->_size;
}

inline int Fifo::time(){
	return this->_time;
}

inline void Fifo::time(int time){
	this->_time = time;
}
