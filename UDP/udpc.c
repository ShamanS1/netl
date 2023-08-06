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
	
	
	char buffer[100];
	printf("enter a message to be sent to server: ");
	fgets(buffer,100,stdin);
	
	
	if(sendto(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,sizeof(server))<0);
	if(sendto==-1)
	printf("error in sendto");
	
	
	
	return 0;
}
