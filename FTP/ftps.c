#include<stdio.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define SERV_TCP_PORT5035
#define max 60
int i,j,tem;
char buff[4096],t;
FILE *f1;
int main()
{
	int sockfd,newsockfd,clength;
	struct sockaddr_in serv_addr,cli_addr;
	char t[max],str[max];
	strcpy(t,"exit");
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=INADDR_ANY;
	serv_addr.sin_port=htons(SERV_TCP_PORT);
	printf("\nBinded");
	bind(sockfd,(struct sockaddr *)&cli_addr,&clength);
	close(sockfd);
	read(newsockfd,&str,max);
	printf("\nClient message\nFilename:%s\n",str);
	f1=fopen(str,"r");
	while(fgets(buff,4096,f1)!=NULL)
	{
		write(newsockfd,buff,max);
		printf("\n");
	}
	fclose(f1);
	printf("\nFile transferred\n");
	return 0;
}
