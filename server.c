/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:15:31 by mrami             #+#    #+#             */
/*   Updated: 2023/01/26 02:56:16 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static void	ft_handle_bit(int sgl, siginfo_t *info, void *ptr)
{
	static int      i;
	static pid_t    C_pid;
	static char     c;

	(void)ptr;
	if (!C_pid)
		C_pid = info->si_pid;
    if (C_pid != info->si_pid)
    {
        c = 0;
        i = 0;
        C_pid = info->si_pid;
    }
	c |= (sgl == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			C_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = ft_handle_bit;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
