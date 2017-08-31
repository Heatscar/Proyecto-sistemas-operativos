#include<stdio.h> 

struct templet{
	char name[8];
	int st,pt,ft,tdr,wt,priority,remain,flag;
	}
	
	p[20],temp;
	void fifo();
	void sjf();
	void rr();
	void prio();
	
int main(){
	int op;
	do{
		printf("1.FIFO\n2.SJF\n3.Round Robin\n4.Prioridad\n5.Salir\n");
		printf("\nOpcion: ");
		scanf("%d",&op);
		switch(op){
			case 1:fifo();
			break;
			case 2:sjf();
			break;
			case 3:rr();
			break;
			case 4:prio();
			break;
			}}while(op!=5);
			}
			
	void fifo(){
	int num,i,fcnt=0;
	float scnt=0;
	printf("\n\tNumero de procesos:");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		printf("\n\tNombre del proceso:");
		scanf("%s",p[i].name);
		printf("\n\tTiempo: ");
		scanf("%d",&p[i].pt);
		}
		for(i=0;i<num;i++){
			p[i].st=fcnt;
			fcnt+=p[i].pt;
			p[i].wt=fcnt-p[i].pt;
			p[i].tdr=fcnt;
			}
			fcnt=0;
			printf("\n\tProceso \tTiempo\t Tiempo de retorno");
			for(i=0;i<num;i++){
				printf("\n\tTR%s\t\t%d\t \t%d\n",p[i].name,p[i].pt,p[i].tdr);
				scnt+=p[i].tdr;
				}
				printf("\nPromedio:%.2f\n",scnt/num);
				printf("\n");
}
	void sjf(){
		int bt[20],p[20],wt[20],tdr[20],i,j,n,total=0,pos,temp;
		float prom_tdr;
		printf("Numero de procesos:");
		scanf("%d",&n);
		printf("\nTiempo:\n");
		for(i=0;i<n;i++){
			printf("p%d:",i+1);
			scanf("%d",&bt[i]);
			p[i]=i+1;
			}
			for(i=0;i<n;i++){
				pos=i;
				for(j=i+1;j<n;j++){
					if(bt[j]<bt[pos])
					pos=j;
					}
					temp=bt[i];
					bt[i]=bt[pos];
					bt[pos]=temp;
					temp=p[i];
					p[i]=p[pos];
					p[pos]=temp;
					}
					wt[0]=0;
					for(i=1;i<n;i++){
						wt[i]=0;
						for(j=0;j<i;j++)
						wt[i]+=bt[j];
						total+=wt[i];
						}
						total=0;
						printf("\nProceso\t    Tiempo    \t\tTiempo de retorno");
						for(i=0;i<n;i++){
							tdr[i]=bt[i]+wt[i];
							total+=tdr[i];
							printf("\np%d\t\t  %d\t\t\t\t%d\n",p[i],bt[i],tdr[i]);
							}
							prom_tdr=(float)total/n;
							printf("\nPromedio=%.2f\n",prom_tdr);
							printf("\n");
}
	void rr(){
		int num,i,j,fcnt=0,quantum;
		float scnt=0;
		printf("\n\tNumero de procesos: ");
		scanf("%d",&num);
		for(i=0;i<num;i++){
			printf("\n\tNombre del proceso: ");
			scanf("%s",p[i].name);
			printf("\n\tTiempo: ");
			scanf("%d",&p[i].pt);
			p[i].remain=p[i].pt;
			p[i].flag=0;
			}
			printf("\n\tQuantum: ");
			scanf("%d",&quantum);
			printf("\n\t Recorrido: \n\t\t");
			i=0;
			while(1){
				for(i=0;i<num;i++){
					if(p[i].flag==0){
					if(p[i].remain<=quantum){
						printf("-- %s --",p[i].name);
						scnt+=p[i].remain;
						p[i].wt=scnt-p[i].pt;
						p[i].tdr=scnt;
						p[i].flag=1;
						fcnt++;
						}
						else{
							printf("-- %s --",p[i].name);
							p[i].remain-=quantum;
							scnt+=quantum;
							}
							}}
							if(fcnt==num)
							break;}
							printf("Final");
							fcnt=0,scnt=0;
							printf("\n\tProceso \t\tTiempo\t\t Tiempo de retorno");
							for(i=0;i<num;i++){
								printf("\n\tTR%s\t\t\t%d\t\t \t%d\n",p[i].name,p[i].pt,p[i].tdr);
								scnt+=p[i].tdr;
								}
								printf("\nPromedio:%.2f\n",scnt/num);
								printf("\n");
} 
	void prio(){
		int num,i,j;
		float fcnt=0,scnt=0;
		printf("\n\tNumero de procesos: ");
		scanf("%d",&num);
		for(i=0;i<num;i++){
			printf("\n\tNombre del proceso: ");
			scanf("%s",p[i].name);
			printf("\n\tTiempo: ");
			scanf("%d",&p[i].pt);
			printf("\n\tPrioridad: ");
			scanf("%d",&p[i].priority);
			}
			for(i=0;i<num;i++){
				for(j=0;j<num;j++){
					if(p[i].priority<p[j].priority){
						temp=p[i];
						p[i]=p[j];
						p[j]=temp;
						}
						}}
						printf("\n\t Recorrido: \n\t\t");
						for(i=0;i<num;i++){
							p[i].st=fcnt; 
							fcnt+=p[i].pt; 
							p[i].wt=fcnt-p[i].pt; 
							p[i].tdr=fcnt;
							printf("%s -->",p[i].name);
							}
							printf("Final");
							fcnt=0;
							printf("\n\tProceso\t\t    Tiempo\t\tTiempo de retorno");
							for(i=0;i<num;i++){
								printf("\n\tTR%s\t\t\t%d\t\t \t%d\n",p[i].name,p[i].pt,p[i].tdr);
								fcnt+=p[i].wt; 
								scnt+=p[i].tdr;
								}
								printf("\nTiempo de espera:%.2f Promedio:%.2f\n",fcnt/num,scnt/num);
								printf("\n");
}

