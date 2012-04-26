#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<sys/types.h>
#include<string.h>

int listenfd;
void startserver(char *);

void respond(int client)
{
    char msg[10000];
    int  bytes_read;

    memset((void*)msg, (int)'\0', 10000);

    bytes_read=recv(client, msg, 10000, 0); //recv max 10000 bytes starting with 0 from the client
    printf("%s", msg);						//prints the HTTP request header
    send(client,"It works!!!",11,0);		//send the response back
    shutdown (client, SHUT_RDWR);         //All further send and recieve operations are DISABLED...
    close(client);
}


main(){
struct sockaddr_in *clientaddr;
char *port="10000";
int c;

c=sizeof(struct sockaddr_in);
startserver(port);

int client;
while(client){

client= accept(listenfd,(struct sockaddr *)&clientaddr, &c);
respond(client);

}

}

void startserver(char *port){
struct addrinfo hints,*res,*p;

memset(&hints,0,sizeof(hints));
hints.ai_family=AF_INET;
hints.ai_flags= AI_PASSIVE;
hints.ai_socktype =SOCK_STREAM;

if(getaddrinfo(NULL,port,&hints,&res) !=0){
printf("getaddrinfo error");
return ;
}

for(p=res;p!=NULL;p=p->ai_next){
listenfd = socket(p->ai_family,p->ai_socktype,0);
if(listenfd==-1)continue;
bind(listenfd,p->ai_addr,p->ai_addrlen);
}

freeaddrinfo(res);
listen(listenfd, 10000);

}


