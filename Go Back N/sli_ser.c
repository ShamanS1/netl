#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
struct frame
{
int packet[40];
};
struct ack
{
int acknowledge[40];
};
int main()
{
int serversocket;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
struct frame f1;
int windowsize,totalpackets,totalframes,i=0,j=0,framesend=0,k,l,buffer;
struct ack acknowledgement;
char req[50];
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5018);
serveraddr.sin_addr.s_addr=INADDR_ANY;
bind(serversocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
bzero((char*)&clientaddr,sizeof(clientaddr));
len=sizeof(clientaddr);
printf("\nWaiting for client connection");
recvfrom(serversocket,req,sizeof(req),0,(struct sockaddr *)&clientaddr,&len);
printf("\nSending request for window size\n");
sendto(serversocket,"REQUEST FOR WINDOWSIZE",sizeof("REQUEST FOR WINDOWSIZE"),0,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
printf("Waiting for the window size\n");
recvfrom(serversocket,(char*)&windowsize,sizeof(windowsize),0,(struct sockaddr *)&clientaddr,&len);
printf("\nThe window size obtained as:\t%d\n",windowsize);
printf("\nObtaining packets from network layer\n");
printf("\nTotal packets obtained:%d\n",(totalpackets=windowsize*5));
printf("\nTotal frames or windows to be transmitted:%d\n",(totalframes=5));
printf("\nSending total number of packets\n");
sendto(serversocket,(char*)&totalpackets,sizeof(totalpackets),0,(struct sockaddr *)&clientaddr,sizeof(clientaddr));
recvfrom(serversocket,req,sizeof(req),0,(struct sockaddr*)&clientaddr,&len);
printf("\nPress enter to start the process\n");
fgets(req,2,stdin);
while(i<totalpackets)
{
bzero((char*)&f1,sizeof(f1));
printf("\nInitializing the transmit buffer\n");
printf("\nThe frame to be send is %d with packets:",framesend);
buffer=i;
j=0;
while(j<windowsize && i<totalpackets)
{
bzero((char*)&f1,sizeof(f1));
printf("\nInitializing the transmit buffer\n");
printf("\nThe frame to be send is %d with packets:",framesend);
buffer=i;
j=0;
while(j<windowsize&&i<totalpackets)
{
printf("%d",i);
f1.packet[j]=i;
j++;
i++;
}
printf("Sending farme %d\n",framesend);
sendto(serversocket,(char*)&f1,sizeof(f1),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
printf("Waiting for the ackowledgement\n");
recvfrom(serversocket,(char*)&acknowledgement,sizeof(acknowledgement),0,(struct sockaddr*)&clientaddr,&len);
j=0;
k=0;
l=buffer;
while(j<windowsize && l<totalpackets)
{
if(acknowledgement.acknowledge[j]==-1)
{
printf("\nnegative ackowledgement recieved for packet:%d\n",f1.packet[j]);
printf("\nRetransmitting from packet:%d\n",f1.packet[j]);
i=f1.packet[j];
i=f1.packet[j];
k=l;
break;
}
j++;
l++;
}
if(k==0)
{
printf("\nPositive acknowledgement recieved for all packets , within the frame:%d\n",framesend);
}
framesend++;
printf("\nPress enter to proceed\n");
fgets(req,2,stdin);
}
printf("\nAll frames sends successfully\nClosing connection with the client\n");
close(serversocket);
}
}
