#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> 
#include <errno.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/epoll.h>

int main() {
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(6666);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sd, (struct sockaddr*)&addr, sizeof(addr));
    int nb = 1;
    //设置非阻塞
    ioctl(sd, FIONBIO, &nb);
    listen(sd, 10);

    //创建epoll
    int efd = epoll_create(256);
    struct epoll_event event;
    event.data.fd = sd;
    event.events = EPOLLIN | EPOLLET;
    //添加event事件
    int s = epoll_ctl(efd, EPOLL_CTL_ADD, sd, &event);

    struct epoll_event events[20];
    while (1)
    {
        int n = epoll_wait (efd, events, 20, 500);
        printf("n 个事件 %d\n", n);
        for(int i = 0; i < n; ++i) {
            if (sd == events[i].data.fd) {
                printf("tcp 连接\n");
            }
        }
        sleep(2);
    }
    return 0;
}