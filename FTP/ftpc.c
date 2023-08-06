#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SERV_TCP_PORT 5035
#define max 60
int main()
{
	int sockfd,n;
	struct sockaddr_in serv_addr;
	struct hostent * server;
	char send[max],recvline[max],s[max],name[max];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(SERV_TCP_PORT);
	connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
	printf("\nEnter the source filename :\n");
	scanf("%s",send);
	write(sockfd,send,max);
	while((n=read(sockfd,recvline,max))!=0)
	{
		printf("%s",recvline);
	}
	close(sockfd);
	return 0;
}
