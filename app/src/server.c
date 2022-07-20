#include "server.h"

void *func_server(){

    int sockfd, connfd, len, n;
    struct sockaddr_in servaddr, cli;
    char buffer[255];
    char *feedback = "Okeee";
    
    // server socket create
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("server create socket failed....\n");
        exit(0);
    }
    else{
        printf("server socket craeted succesfully..\n");
    }

    memset(&servaddr, '0', sizeof(servaddr));

    // asign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding new socket created
    if(bind(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0){
        perror("server soket bind failed.....\n");
        exit(0);
    }
    else{
        printf("server socket binding....\n");
    }
    

    // server is ready listen
    if(listen(sockfd, 6) != 0){
        perror("Server socket listen failed.....\n");
        exit(0);
    }
    else{
        printf("server listenning....\n");
    }
   

    len = sizeof(cli);
    // server accept cli
    connfd = accept(sockfd, (SA*)&cli, &len);
    if(connfd < 0){
        perror("server accept failed...\n");
        exit(0);
    }
    else{
        printf("server accepted...\n");
        
    }
    bzero(buffer, sizeof(buffer));
    read(connfd, buffer, sizeof(buffer));
    printf("From client: %s", buffer);
    send(connfd, feedback, strlen(feedback), 0);
    return NULL;

}