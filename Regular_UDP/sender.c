//sender_s
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
struct sockaddr_in serv;

int main() {

	socklen_t size = sizeof(serv);	

	char buf[]="Hello from server";

	int fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	serv.sin_family = AF_INET;
	serv.sin_port = htons (5555);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);

	sendto (fd, buf, sizeof(buf), 0, (struct sockaddr *)&serv, size);
	printf("Sent: %s\n", buf);

	recvfrom (fd, buf, sizeof(buf), 0, (struct sockaddr *)&serv, &size);
	printf("Recieved: %s \n", buf);	

	close(fd);
	
	return 0;
}
