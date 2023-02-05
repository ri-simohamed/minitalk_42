/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:21:13 by mrami             #+#    #+#             */
/*   Updated: 2023/02/05 22:47:07 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


static void	ft_handle_bits(int sgl, siginfo_t *info, void *ptr)
{
	static int		i;
	static pid_t	c_pid;
	static char		c;

	(void)ptr;
	if (!c_pid)
		c_pid = info->si_pid;
	if (c_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		c_pid = info->si_pid;
	}
	c |= (sgl == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(int argc, char const *argv[])
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_flags = SA_SIGINFO;
	if (argc == 1)
	{
		ft_putstr_fd("PID-> ", 1);
		ft_putnbr_fd(getpid(), 1);
		ft_putchar_fd('\n', 1);
		sa.sa_sigaction = ft_handle_bits;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Somthing Worrng Please Try agin!", 1);
	return (0);
}

