#include "Sjf.h"

void Sjf::insert(char id, int time, int priority){
	Node *new_node = new Node(id, time, priority);	
	if(empty()){
		this->initial = new_node;
		this->final = new_node;
	}
	else{
		Node *aux = this->initial;
		if (new_node->time() <= this->initial->time()){
			new_node->next(this->initial);
			this->initial = new_node;
		}
		else if (new_node->time() >= this->final->time()){
			this->final->next(new_node);
			this->final = new_node;
		}
		else{
			while(new_node->time() >= aux->next()->time())
				aux = aux->next();
			new_node->next(aux->next());
			aux->next(new_node);
		}
	}
	this->_size ++;
	this->_time = 0;
}
