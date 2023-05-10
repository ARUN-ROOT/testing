/*
* Name		: 
* Date		: 22/4/23			
* Author	: 
* Descrption	:
* Output	:
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main()
{

  int sock_fd,c_fd;
  sock_fd=socket(AF_INET,SOCK_STREAM,0);
  
  struct sockaddr_in serveraddress;
  serveraddress.sin_family=AF_INET;
  serveraddress.sin_port=htons(8080);
  //serveraddress.sin_addr.s_addr=INADDR_ANY;
  serveraddress.sin_addr.s_addr=inet_addr("192.168.1.121");
  
   //int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
  connect(sock_fd,(struct sockaddr *)&serveraddress,sizeof(serveraddress));
  
  char serverresponse[1024];
  recv(sock_fd,&serverresponse,sizeof(serverresponse),0);
  printf("server sent data : %s\n",serverresponse);
  
  close(c_fd);
  
  

}



