/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:57:55 by mrami             #+#    #+#             */
/*   Updated: 2023/02/04 22:02:15 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static	void	ft_send_bits(int pid, char c)
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
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (0);
		while (argv[2][i] != '\0')
		{
			ft_send_bits(pid, argv[2][i++]);
		}
		ft_send_bits(pid, '\n');
	}
	else
		ft_putstr_fd("Somthing Worrng Please Try Again!", 1);
	return (0);
}
