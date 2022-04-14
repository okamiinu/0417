#include <stdio.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
  
int main()  
{  
  int sock0;  
  struct sockaddr_in addr;  
  struct sockaddr_in client;  
  socklen_t len;  
  int sock_client;  
  
  /* �s�@ socket */  
  sock0 = socket(AF_INET, SOCK_STREAM, 0);  
  
  /* �]�w socket */  
  addr.sin_family = AF_INET;  
  addr.sin_port = htons(12345);  
  addr.sin_addr.s_addr = INADDR_ANY;  
  bind(sock0, (struct sockaddr*)&addr, sizeof(addr));  
  printf("\t[Info] binding...\n");  
  
  /* �]�w�����ݨӦ� TCP �Τ�ݪ��s�u�n�D���A */  
  listen(sock0, 5);  
  printf("\t[Info] listening...\n");  
  
  /* �����Ӧ� TCP �Τ�ݦa�s�u�n�D*/  
  printf("\t[Info] wait for connection...\n");  
  len = sizeof(client);  
  sock_client = accept(sock0, (struct sockaddr *)&client, &len);  
  printf("\t[Info] Testing...\n");  
  char *paddr_str = inet_ntoa(client.sin_addr);  
  printf("\t[Info] Receive connection from %s...\n", paddr_str);  
  
  /* �ǰe 5 �Ӧr�� */  
  printf("\t[Info] Say hello back...\n");  
  write(sock_client, "HELLO\n", 6);  
  
  /* ���� TCP ��� */  
  printf("\t[Info] Close client connection...\n");  
  close(sock_client);  
  
  /* ���� listen �� socket */  
  printf("\t[Info] Close self connection...\n");  
  close(sock0);  
  return 0;  
}  
