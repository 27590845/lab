#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    int i;
    char *arg = arg[1];
    int num = atoi(arg);
    sleep(num);

    exit(0);
}
