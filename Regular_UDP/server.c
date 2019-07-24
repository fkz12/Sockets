#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
struct sockaddr_in serv, from;

int main() {
	
	socklen_t size =  sizeof(serv);
	char buf[35];
	int fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	serv.sin_family = AF_INET;
	serv.sin_port = htons (5555);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(fd, (struct sockaddr *)&serv, sizeof(serv));

	recvfrom (fd, buf, sizeof(buf), 0, (struct sockaddr *)&serv, &size);

	printf("Recieved: %s \n", buf);
	buf[0]='7';
	printf("Sent: %s\n", buf);

	sendto (fd, buf, sizeof(buf), 0, (struct sockaddr *)&serv, size);
	close(fd);
	return 0;	
}
