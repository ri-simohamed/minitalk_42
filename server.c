/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:15:31 by mrami             #+#    #+#             */
/*   Updated: 2023/01/26 20:01:29 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static	void	ft_handle_bit(int sgl, siginfo_t *info, void *ptr)
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

int	main(void)
{
	struct sigaction	s_sigaction;

	s_sigaction.sa_flags = SA_SIGINFO;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_handle_bit;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
