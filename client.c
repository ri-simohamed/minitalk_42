/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:06:59 by mrami             #+#    #+#             */
/*   Updated: 2023/02/07 16:59:51 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_bits(int pid, char c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(700);
	}
}

int	main(int argc, char const *argv[])
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
		{
			ft_putstr_fd("Cannot be send To PID = 0.\n", 1);
			return (0);
		}
		if (argv[1] < 0)
			return (0);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i++]);
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_putstr_fd("Somthing Worrgn Please Try Agin!", 1);
	}
	return (0);
}
