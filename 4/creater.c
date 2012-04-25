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

if((shmid=shmget(key,SHMSZ,IPC_CREAT|0666))<0){
printf("error");
return 1;
}

if((shm=shmat(shmid,NULL,0))==(char *)-1){
printf("error");
return 1;
}

s=shm;

for(c='a';c<='z';c++){
*s=c;
s++;
}
while(*s!='*')
sleep(1);

return 0;

}
