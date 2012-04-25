#include<stdio.h>
#include<sys/socket.h>		//socket creation
#include<arpa/inet.h>		// inet_addr

#include<netdb.h>		// Getting host name

#include<string.h>

main(){
int socket_desc,i;
struct sockaddr_in server;
char *message,server_reply[2000];

char *hostname = "www.google.com";
char ip[100];
struct hostent *he;
struct in_addr **addr_list;

	if ( (he = gethostbyname( hostname ) ) == NULL)
	{
		//gethostbyname failed
		herror("gethostbyname");
		return 1;
	}

	//Cast the h_addr_list to in_addr , since h_addr_list also has the ip address in long format only
	addr_list = (struct in_addr **) he->h_addr_list;

	for(i = 0; addr_list[i] != NULL; i++)
	{
		//Return the first one;
		strcpy(ip , inet_ntoa(*addr_list[i]) );
	}

	printf("%s resolved to : %s" , hostname , ip);

// Client code
socket_desc = socket(AF_INET, SOCK_STREAM, 0);

if(socket_desc == -1){
printf("Couldn't create socket");
}

server.sin_addr.s_addr= inet_addr(ip);
server.sin_family = AF_INET;
server.sin_port= htons(80);

if(connect(socket_desc, (struct sockaddr *)&server,sizeof(server))<0){
puts("connect error\n");
return 1;
}

printf("Connected\n");

message = "GET / HTTP/q.q\r\n\r\n";
if(send(socket_desc,message,strlen(message),0)<0)
{
printf("Sending failed\n");
return 1;
}
printf("Data send\n");

if(recv(socket_desc,server_reply,2000,0)<0){
printf("receiving failed");
return 1;
}

printf("Reply received \n");
printf("%s",server_reply);

close(socket_desc);
return 0;
}

