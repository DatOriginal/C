#include "client.h"

void *func_client(){
    
    int sockfd, valread, n;
    struct sockaddr_in servaddr, cli;
    char buffer[255];

    
    // client socket create
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("Client socket creare failed..\n");
        exit(0);
    }
    else{
        printf("client socket creatty succesfully...\n");
    }

    memset(&servaddr, '0', sizeof(servaddr));

    // asign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    // Connect to server
    if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0){
        perror("Connection to server failed....\n");
        exit(0);
    } 
    else{
        printf("Connected to server.....\n");
        
    }
    sleep(1);
    bzero(buffer, sizeof(buffer));
    printf("Enter the string : ");
    n = 0;
    while ((buffer[n++] = getchar()) != '\n')
        ;
    write(sockfd, buffer, sizeof(buffer));
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("From Server : %s\n", buffer);
    
    return NULL;
}