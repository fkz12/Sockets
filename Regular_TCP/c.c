//client
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
struct sockaddr_in serv;

int main() {

	char buf[20];
	int fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	serv.sin_family = AF_INET;
	serv.sin_port = htons (7777);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);

	connect (fd, (struct sockaddr *)&serv, sizeof(serv));	
	recv (fd, buf, sizeof(buf), 0);

	printf("%s", buf);
	buf[0]='7';
	sleep(1);
	send(fd, buf, sizeof(buf), 0);
	
	close(fd);
	
	return 0;	
}
