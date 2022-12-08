/*
 * echoclient.c - An echo client
 */
/* $begin echoclientmain */
#include "csapp.h"

int main(int argc, char **argv) 
{
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;
    char myStr[MAXLINE];
    int num,connect_idx,flag,length;

    if (argc != 3) {
	fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);

    printf("--> Hailstone Sequence Client v1.0\n");
    printf("--> Connection Established To localhost Port\n");
    printf("[HSS:1:1] Welcome to the Hailstone Sequence Server v1.0\n\n");
    flag = 1;
    connect_idx = 2; 
    printf("-->Enter A Positive Integer (^d to quit): ")
    // while(1) {
    //     printf("-->Enter A Positive Integer (^d to quit): ");
    //     scanf("%s", myStr);
    //     if(strcmp(myStr, "^d") == 0){
    //             printf("--> Disconnected from localhost port x. Goodbye.\n");
    //             Close(clientfd);
    //             exit(0);
    //     }if((strcmp(myStr, "0") == 0) || (strstr(myStr, "-") != NULL)||(strcmp(myStr, "") == 0)){
    //         printf("Retry with possitive integer \n");
            
    //     }else{
    //             //hailstone program here
    //             // printf("Your String is %s\n",myStr);
    //             // printf("count %d\n",connect_idx);
    //             length = 1;
    //             num = atoi(myStr);
    //             printf("[HSS:%d:x] Sequence start with %d \n",connect_idx,num);
    //             while(num != 1)
    //             {
    //                 if( num % 2 )  /* true if odd */
    //                     num = (num*3)+1;
    //                 else                /* even */
    //                     num /= 2;
    //                 printf("[HSS:%d:x] %d \n",connect_idx,num);
    //                 length++;
    //             }
    //             printf("[HSS:%d:x] Finished.  Number of iterations = %d\n\n",connect_idx,(length-1));
    //             connect_idx++;          
    //         }
        
    // }
    Rio_readinitb(&rio, clientfd);

    while (Fgets(buf, MAXLINE, stdin) != NULL) {
    
    Rio_writen(clientfd, buf, strlen(buf));
    Rio_readlineb(&rio, buf, MAXLINE);
    // Fputs(buf, stdout);
    
    }
    Close(clientfd);
    exit(0); //line:netp:echoclient:close
    
}
/* $end echoclientmain */
