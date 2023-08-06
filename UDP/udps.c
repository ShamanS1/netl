#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
int main()
{
    struct sockaddr_in server,client;
    
    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    if(sockfd==-1)
    printf("Error in socket();"); 
    
    
    server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=3000;
	
	
	int k = bind(sockfd,(struct sockaddr*)&server,sizeof(server))<0;
	if (k==-1)
	printf("\nerror in bind");
	
	char buffer[100];
	socklen_t server_len=sizeof(server);
	printf("\nserver waiting....\n");
	if((recvfrom(sockfd,buffer,100,0,(struct sockaddr*)&server,&server_len)<0)==-1)
	printf("error in recvfrom()!");
	printf("got the datagram:%s",buffer);
	
	
	return 0;
}
