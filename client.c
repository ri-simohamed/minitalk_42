/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:57:55 by mrami             #+#    #+#             */
/*   Updated: 2023/01/24 22:40:33 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	num;
	int		sign;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = 10 * num + str[i] - '0';
		i++;
	}
	return (sign * num);
}

static void ft_send_bits(int pid, char c)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
    if ((c & (1 << bit)) != 0)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(700);
    bit++;
    }
}

int main(int argc, char const *argv[])
{
    
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i] != '\0')
        {
            ft_send_bits(pid, argv[2][i++]);
        }
        ft_send_bits(pid, '\n');
    }
    else
    {
        ft_printf("Some thing Wornng Please Try Agin!");
    }
    
    return (0);
}
