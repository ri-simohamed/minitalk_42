/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:55:21 by mrami             #+#    #+#             */
/*   Updated: 2023/02/06 17:51:15 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_bits_bonus(int pid, char c)
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
			return (0);
		if (argv[1] < 0)
			return (0);
		while (argv[2][i] != '\0')
		{
			ft_send_bits_bonus(pid, argv[2][i++]);
		}
		ft_send_bits_bonus(pid, '\n');
		ft_putstr_fd("Massege Well Be Send Succssefull.", 1);
	}
	else
		ft_putstr_fd("Somthing Worrng Please Try Agin!.", 1);
	return (0);
}
