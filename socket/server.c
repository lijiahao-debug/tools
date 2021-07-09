#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> 
#include <errno.h>
#include <arpa/inet.h>

int main() {
    int sd;
    if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6666);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(sd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        printf("bind error\n");
        exit(1);
    }

    if(listen(sd, 10) == 1) {
        printf("listen error\n");
        exit(1);
    }
    while(1) {
        struct sockaddr_in inaddr;
        socklen_t sl = sizeof(inaddr);
        int confd = accept(sd, (struct sockaddr*)&inaddr, &sl);
        char buff[1024] = {0};
        int len = recv(confd, buff, 1024, 0);
        buff[len] = '\0';
        //inet_ntop(AF_INET, (void *) &ip, result, size);
        printf("receive a msg from %s: %s\n", inet_ntoa(inaddr.sin_addr), buff);
        close(confd);
    }
    return 0;
}