#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHMSZ 27
main(){

key_t key;
int  shmid;
key = 2222;
char *shm,*s,c;

if((shmid=shmget(key,SHMSZ,0666))<0){
printf("error");
return 1;
}

if((shm=shmat(shmid,NULL,0))==(char *)-1){
printf("error");
return 1;
}

s=shm;

for(;*s!='z';s++){
printf("%c",*s);
*s='*';
}
*s='*';
s++;
*s ='*';
return 0;

}

