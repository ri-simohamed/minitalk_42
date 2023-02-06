/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:09:39 by mrami             #+#    #+#             */
/*   Updated: 2023/02/06 19:13:22 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	char	*ft_char_to_bits(unsigned char c)
{
	char	*str;
	int		i;

	str = malloc(9);
	str[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		str[i] = (c % 2) + '0';
		c = c / 2;
		i--;
	}
	return (str);
}

int	ft_count_bits(unsigned char c)
{
	char	*bits;
	int				i;

	bits = ft_char_to_bits(c);
	i = 0;
	while (bits[i] && bits[i] == '1')
		i++;
	free(bits);
	return (i);
}

static void	ft_handle_bits_bonus(int sgl, siginfo_t *info, void *ptr)
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
		sa.sa_sigaction = ft_handle_bits_bonus;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Somthing Worrng Please Try agin!", 1);

	return (0);
}

