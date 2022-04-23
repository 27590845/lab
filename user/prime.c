#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user/user.h"

int read_and_write(int p1)
{
    int in[1];
    int flag = 0;
    int while_flag = 1;
    int p[2];
    pipe(p);
    while (while_flag && read(p1, in, sizeof(int)))
    {

        if (in[0] == 0)
        {
            // end num
            close(p1);
            if (flag == 0)
            {
                // end pipe;
                exit(0);
            }
            while_flag = 0;
        }
        else if (flag == 0)
        {
            printf("prime %d", in[0]);
            flag = 1;
            if (fork() == 0)
            {
                read_and_write(p[1]);
            }
        }
        else
        {
            write(p[0], in, sizeof(int));
        }
    }
    close(p[0]);
    wait(0);
    exit(0);
}

int main(int argc, char *argv[])
{

    int nums = 35;
    int p[2];
    int out[1];
    pipe(p);
    if (fork() == 0)
    {
        read_and_write(p[1]);
    }
    else
    {
        while (nums--)
        {
            out[0] = nums;
            write(p[0], out, sizeof(int));
        }
    }
    close(p[0]);
    wait(0);
    exit(0);
}