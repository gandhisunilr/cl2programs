#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>

#include<string.h>

main(int argc, char *argv[]){
struct hostent *host;
struct in_addr **addr_list;
struct sockaddr_in server;
int socket_desc,port;
char *ip;

host=gethostbyname(argv[1]);
addr_list=(struct sockaddr_in **)host->h_addr_list;
ip=inet_ntoa(*addr_list[0]);

printf("%s\n",ip);

for(port=0;port<65000;port++){
if((socket_desc = socket(AF_INET, SOCK_STREAM,0))<0){
printf("Socket conncetion failed");
return 1;
}

server.sin_family = AF_INET;
server.sin_port =htons(port);
server.sin_addr.s_addr= inet_addr(ip);

	if(connect(socket_desc, (struct sockaddr *)&server,sizeof(server))<0){
	close(socket_desc);
	continue;
	}else{
	printf("%d is open\n",port);
	close(socket_desc);
	}

}

return 0;
}
