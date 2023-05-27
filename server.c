#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "inc_printf/ft_printf.h"
#include "inc_libft/libft.h"
#include "inc_mm/memory_manager.h"

#include <stdio.h>

static char	*str = NULL;

char	*ft_strcjoin(char *s1, char c)
{
	int		i;
	int		j;
	int		s3len;
	char	*s3;

	i = 0;
	j = 0;
	if (!c)
		return (NULL);
	s3len = ft_strlen(s1) + 1;
	s3 = ftm_malloc(sizeof(char) * (s3len + 1));
	if (!s3)
		return (NULL);
	while (j < s3len)
	{
		while (s1[i])
			s3[j++] = s1[i++];
		s3[j++] = c;
	}
	s3[j] = '\0';
	ftm_free(s1);
	return (s3);
}

int	reverse_converter(int *tab)
{
	int		decimal;
	int		c_value;
	int		i;

	decimal = 128;
	c_value = 0;
	i = 8;
	while (i > 0)
	{
		if (tab[i - 1] == 1)
			c_value += decimal;
		decimal /= 2;
		i--;
	}
	return (c_value);
}

void	sig_catcher(int sig)
{
	int			tab[8];
	static int	bit = 0;

	if (sig == SIGUSR1)
		tab[bit] = 1;
	if (sig == SIGUSR2)
		tab[bit] = 0;
	bit++;
	if (!str)
		str = ftm_malloc(sizeof(char));
	if (bit == 8)
	{
		if (reverse_converter(tab) == 127)
		{
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			bit = 0;
			str = NULL;
			kill(pid)
			return ;
		}
		str = ft_strcjoin(str, (char)reverse_converter(tab));
		bit = 0;
	}
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
	/////////////////////////////
	sa.sa_handler = &sig_catcher;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	/////////////////////////////
	while (1)
		pause();
	return (0);
}
