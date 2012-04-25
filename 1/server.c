#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#include<string.h>

#include<pthread.h>

void *connection_handler(void *);

main(){
int socket_desc,c,client_socket;
struct sockaddr_in server,client;
char *message;

socket_desc= socket(AF_INET, SOCK_STREAM,0);
	if(socket_desc == -1){
	printf("Socket not created");
	return 1;
	}
server.sin_family = AF_INET;
server.sin_port = htons(8888);
server.sin_addr.s_addr = INADDR_ANY;

	 if(bind(socket_desc, (struct sockaddr *)&server,sizeof(server))<0){
	printf("server binding failed");
	return 1;
	}

printf("Binding completed");

listen(socket_desc,3);

c=sizeof(struct sockaddr_in);

	while(client_socket=accept(socket_desc,(struct sockaddr *)&client,&c)){

		if(client_socket<0){
		printf("accept failed\n");
		}

	printf("Connection Accepted\n");

	message="I have got your message, But I will not answer it Bcoz you bore me\n";
	write(client_socket,message,strlen(message));

	pthread_t handler_thread;

	pthread_create(&handler_thread,NULL,connection_handler, (void *)&client_socket);

	printf("Handler asssigned");
	}

close(socket_desc);

return 0;	
}

void *connection_handler(void *socket_desc){
char *message,client_message[2000];
int read_size;

message = "I am gonna handle you ";
write(*(int *)socket_desc, message,strlen(message));

	while(1){
		if((read_size= recv(*(int *)socket_desc,client_message,2000,0))>0)
		{
		printf("%s",client_message);
		write(*(int *)socket_desc, client_message,strlen(client_message));
		
		}
		
		if(read_size == 0){
		printf("Kamina muzhe chod ke chala gaya :-\(");
		break;
		}
	}
}
