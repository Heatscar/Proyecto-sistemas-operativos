#include <cstdio>
#include "Priority.h"

void Priority::insert(char id, int time, int priority){
	Node *new_node = new Node(id, time, priority);
	if(empty()){
		this->initial = new_node;
		this->final = new_node;
	}

	else{
		Node *aux = this->initial;
		if (new_node->priority() >= this->initial->priority()){
			new_node->next(this->initial);
			this->initial = new_node;
		}

		else if (new_node->priority() <= this->final->priority()){
			this->final->next(new_node);
			this->final = new_node;
		}

		else{
			while(new_node->priority() <= aux->next()->priority())
				aux = aux->next();

			new_node->next(aux->next());
			aux->next(new_node);
		}
	}

	this->_size ++;
	this->_time += time;
	this->_quantum = this->_time / this->_size;
}

void Priority::insert(Node *unfinished){
	Node *aux = this->initial;

	if(aux->next() != NULL){
		while(unfinished->priority() < aux->priority() && aux->next() != NULL)
		aux = aux->next();
		Node *aux2 = aux->next();
		aux->next(unfinished);
		unfinished->next(aux2);
	}

}

void Priority::pop(){
	this->_time += initial->time() >= quantum() ? quantum() : initial->time();
	Node *aux = this->initial;
	aux->time(aux->time() - quantum());
	this->initial = this->initial->next();
	aux->next(NULL);
	aux->priority( aux->priority() - 1);
	if(aux->time() > 0) insert(aux);
	else{
        printf("Termina %c\n", aux->id());
		delete aux;
		this->_size --;
	}
}

inline int Priority::quantum(){
	return this->_quantum;
}
