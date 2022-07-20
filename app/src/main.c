#include "server.h"
#include "client.h"


int main(int argc, char **argv[]){
    pthread_t ser, cli;

    pthread_create(&ser, NULL, &func_server, NULL);
    sleep(1);
    pthread_create(&cli, NULL, &func_client, NULL);
    
    pthread_join(ser, NULL);
    pthread_join(cli, NULL);
    
    return 0;
}