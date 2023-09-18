#include <stdio.h>
#include <WinSock.h>
#pragma comment(lib, "wsock32.lib")

int main(int argc, char *argv[])
{
	WORD wVersionRequested = MAKEWORD( 1, 1 );
	WSADATA wsaData;
	char Name[256], *ip;
	PHOSTENT host;
	int i;

	ip = (char *)malloc(256);
	WSAStartup( wVersionRequested, &wsaData );
	gethostname(Name, sizeof(Name));

	host = gethostbyname(Name);
	ip = inet_ntoa(*(struct in_addr *)host->h_addr_list[0]);
	printf("Endereco Ipv4: %s\n", ip);

	flushall();
	getchar();
	return 0;
}
