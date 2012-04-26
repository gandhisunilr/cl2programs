#include<stdio.h>
#include<stdlib.h>

struct nodestruct{
char ip[20];
int alive;
}nodes[100];

int ping_node(struct nodestruct *node){
int status,ping_ret;
char sbuf[50];
sprintf(sbuf,"ping -w 3 %s",node->ip);
status=system(sbuf);
if(status != -1)
ping_ret = WEXITSTATUS(status);
return !ping_ret;
}
void bully(int no_proc,int currentcoor){

}
void ring(int no_proc,int currentcoor){

}
main()
{
	int i,choice = 1,no_proc,coordinatorid;
	
	printf("\nEnter no. of Nodes : ");
	scanf("%d",&no_proc);
	for(i=0;i<no_proc;i++)
	{
		printf("\nEnter Node %d IP  : ",i);
		scanf("%s",nodes[i].ip);
		nodes[i].alive = (ping_node(&nodes[i]));
		printf("%d", nodes[i].alive);
		printf("\nGot the host %s is",nodes[i].ip);
		nodes[i].alive==0? printf(" Dead\n") : printf(" Alive\n");
	}
	for(i=0;i<no_proc;i++){
		if(nodes[i].alive==1){
			coordinatorid=i;
		}
	}
	printf("%d",coordinatorid);

	printf("\n---Election Algorithym---");
	printf("\n1. Bully Algo");
	printf("\n2. Ring Algo");
	printf("\n3. Display");
	printf("\n4.Exit");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
				bully(no_proc,coordinatorid);
				break;
		case 2:
				ring(no_proc,coordinatorid);
				break;
		case 3:
				break;
		case 4:
				exit(0);
				break;
	}
		return 0;

}

