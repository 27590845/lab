#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int p[2];
    pipe(p);
    char in[1];
    char out[1] = {'1'};
    if (fork() == 0)
    {
        read(p[1], in, 1);
        printf("%d: received ping", getpid());
        write(p[0], out, 1);
    }
    else
    {
        write(p[0], out, 1);
        sleep(1);
        read(p[1], in, 1);
        printf("%d: received pong", getpid());
    }

    exit(0);
}
