/*
* Name		: 
* Date		: 22/4/23			
* Author	: 
* Descrption	:
* Output	:
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
  int sock_fd,c_fd;
  
  char servermsg[]="How are u";
  
  sock_fd=socket(AF_INET,SOCK_STREAM,0);
  
  struct sockaddr_in serveraddress;
  serveraddress.sin_family=AF_INET;
  serveraddress.sin_port=htons(8080);
  //serveraddress.sin_addr.s_addr=INADDR_ANY;
  serveraddress.sin_addr.s_addr=inet_addr("192.168.1.121");
  
  // int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
  bind(sock_fd,(struct sockaddr*)&serveraddress,sizeof(serveraddress));
  perror("bind()");
  
  // int listen(int sockfd, int backlog);
  listen(sock_fd,5);
  perror("listen()");
  
  // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
  c_fd=accept(sock_fd,NULL,NULL);
  perror("accept()");
  
  send(c_fd,servermsg,sizeof(servermsg),0);
  
  close(sock_fd);
  return 0;  
}









