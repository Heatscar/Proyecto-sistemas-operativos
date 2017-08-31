#include <cstdio>

#include "Fifo.cpp"
#include "Sjf.cpp"
#include "Round_Robin.cpp"
#include "Priority.cpp"

void run(Fifo *f){
	float size = float(f->size());
	int time = 0;
	while(!f->empty()){
		printf("Tiempo: %i\n", f->time());
		time += f->time();
		f->print_full();
		f->pop();
		puts("");
	}
	printf("Tiempo: %i\n", f->time());
	time += f->time();
	printf("\nTiempo total: %i\n", time);
	printf("Promedio: %.2f\n", time / size);
}

void run(Round_Robin *r){
    int time = 0;
    float size = float(r->size());
    r->time(0);
    int is_death = size;
	while(!r->empty()){
		printf("Quantum: %i\n", r->quantum());
		printf("Tiempo: %i\n", r->time());
		r->print_full();
		r->pop();
		if(r->size() < is_death){
			time += r->time();
			is_death = r->size();
		}
		puts("");
	}
	printf("Tiempo: %i\n", r->time());
	printf("\nTiempo total: %i\n", time);
	printf("Promedio: %.2f\n", time / size);
}

void run(Priority *r){
    int time = 0;
    float size = float(r->size());
    r->time(0);
	int is_death = size;
	while(!r->empty()){
		printf("Quantum: %i\n", r->quantum());
		printf("Tiempo %i\n", r->time());
		r->print_full();
		r->pop();
		if(r->size() < is_death){
			time += r->time();
			is_death = r->size();
		}
		puts("");
	}
	printf("Tiempo: %i\n", r->time());
	printf("\nTiempo total: %i\n", time);
	printf("Promedio: %.2f\n", time / size);
}

int main(){
	Fifo *f = new Fifo();
	Sjf *s = new Sjf();
	Priority *p = new Priority();
	Round_Robin *r = new Round_Robin();

	int i;
	char id;
	int time;
	int priority;

	do{
		puts("Nombre ID:");
		scanf(" %c", &id);

		puts("Ingrese tiempo:");
		scanf("%i", &time);

		puts("Prioridad:");
		scanf("%i", &priority);

		f->insert(id, time, priority);
		s->insert(id, time, priority);
		r->insert(id, time, priority);
		p->insert(id, time, priority);

		puts("\nAñadir Otro Elemento 1=SI 2=NO");
		scanf("%i", &i);
		if (i == 2){
		system("cls");	
		}
	}
	while(i == 1);
				printf("FIFO\n");
				run(f);
				printf("-----------------------------------\n");

				printf("SJF\n");
				run(s);
				printf("-----------------------------------\n");

				printf("ROUND ROBIN\n");
				run(r);
				printf("-----------------------------------\n");
				
				printf("PRIORIDAD\n");
				run(p);			
	return 0;
}
