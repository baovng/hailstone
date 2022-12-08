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
    printf("Received %s\n", buf);
    printf("Sending sequence \n");
	Rio_writen(connfd, buf, n);
    }
}
/* $end echo */

