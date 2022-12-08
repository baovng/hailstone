/* 
 * echoserverp.c - A concurrent echo server based on processes
 */
/* $begin echoserverpmain */
#include "csapp.h"
void compute(int connfd);

void sigchld_handler(int sig) //line:conc:echoserverp:handlerstart
{
    while (waitpid(-1, 0, WNOHANG) > 0)
	;
    return;
} //line:conc:echoserverp:handlerend

int main(int argc, char **argv) 
{
    int listenfd, connfd;
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
	char client_hostname[MAXLINE], client_port[MAXLINE];

    if (argc != 2) {
	fprintf(stderr, "usage: %s <port>\n", argv[0]);
	exit(0);
    }

    Signal(SIGCHLD, sigchld_handler);
    listenfd = Open_listenfd(argv[1]);
	printf("Hailstone Sequence Server v1.0\n");
	printf("Listening On Port \n\n");
	printf("Waiting for connection...\n");

	int counter;
	for(counter=0; counter<argc; counter++)
		printf("argv[%2d]: %s\n",counter,argv[counter]);

    while (1) {
	clientlen = sizeof(struct sockaddr_storage); 
	connfd = Accept(listenfd, (SA *) &clientaddr, &clientlen);

	
	if (Fork() == 0) { 
	    Close(listenfd); /* Child closes its listening socket */
		Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
	
		printf("Server connected to localhost (127.0.0.1:%s)\n", client_port);
		// printf("Server connected to localhost (%s, %s)\n", client_hostname, client_port);

	    compute(connfd);    /* Child services client */ //line:conc:echoserverp:echofun
	    Close(connfd);   /* Child closes connection with client */ //line:conc:echoserverp:childclose
	    exit(0);         /* Child exits */
	}
	Close(connfd); /* Parent closes connected socket (important!) */ //line:conc:echoserverp:parentclose
    }
}
/* $end echoserverpmain */
