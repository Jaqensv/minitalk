#include <signal.h>
#include "inc_libft/libft.h"

#include <stdio.h>

void    converter(int pid, char c)
{
    int i;

    i = -1;
    while (++i < 8)
    {
        if ((c & 0x01 << i) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(80);
    }
}

int main(int argc, char **argv)
{
    int i;
    int pid;

    if (argc != 3)
        exit(1);
    i = -1;
    pid = ft_atoi(argv[1]);
    while (argv[2][++i])
        converter(pid, argv[2][i]);
    converter(pid, 127);
}
