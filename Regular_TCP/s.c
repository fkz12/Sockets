//server
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
struct sockaddr_in serv;

int main() {

	char buf[]="From server\n";
	int fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	serv.sin_family = AF_INET;
	serv.sin_port = htons (7777);
	serv.sin_addr.s_addr = htonl(INADDR_ANY);

	bind (fd, (struct sockaddr*)&serv, sizeof(serv));
	listen(fd, 5);
	
	int new_fd = accept (fd, (struct sockaddr*)NULL, NULL);
	
	send (new_fd, buf, sizeof(buf), 0);
	recv (new_fd, buf, sizeof(buf), 0);

	printf("%s", buf);	
	close(new_fd);
	
	return 0;	
}
