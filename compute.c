/*
 * echo - read and echo text lines until client closes connection
 */
/* $begin echo */
#include "csapp.h"

void compute(int connfd) 
{
    int n; 
    char buf[MAXLINE]; 
    rio_t rio;

    Rio_readinitb(&rio, connfd);
    while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0) {
	printf("Received %d bytes\n", Rio_readlineb(&rio, buf, MAXLINE));
    printf("Received %d bytes\n", Rio_writen(connfd, buf, n));
    printf("Received %s bytes\n", buf);
	Rio_writen(connfd, buf, n);
    }
}
/* $end echo */

