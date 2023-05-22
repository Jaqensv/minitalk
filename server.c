#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "inc_printf/ft_printf.h"

#include <stdio.h>

static int	bit = 0;

void	reverse_converter(int *tab)
{
	int	decimal;
	int	c_value;

	decimal = 128;
	c_value = 0;
	while (bit > 0)
	{
		if (tab[bit - 1] == 1)
			c_value += decimal;
		decimal /= 2;
		bit--;
	}
}

void	sig_catcher(int sig)
{
	int	tab[8];

	if (sig == SIGUSR1)
		tab[bit] = 1;
	if (sig == SIGUSR2)
		tab[bit] = 0;
	bit++;
	if (bit == 8)
		reverse_converter(tab);
}

int main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	if (argc != 1)
		exit(1);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	//////////////////////////////
	sa.sa_handler = &sig_catcher;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	//////////////////////////////
	while (1)
		pause();
	return (0);
}

// ussleep 80