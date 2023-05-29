/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-lang <mde-lang@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 23:32:07 by mde-lang          #+#    #+#             */
/*   Updated: 2023/05/29 22:54:03 by mde-lang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc_libft/libft.h"
#include <signal.h>
#include <stdio.h>

void	ft_converter(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c & 0x01 << i) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(70);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		exit(1);
	i = -1;
	pid = ft_atoi(argv[1]);
	while (argv[2][++i])
		ft_converter(pid, argv[2][i]);
	ft_converter(pid, 127);
}
