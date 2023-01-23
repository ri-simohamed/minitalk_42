/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:57:55 by mrami             #+#    #+#             */
/*   Updated: 2023/01/22 17:01:00 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

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
    usleep(100);
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
            ft_send_bits(pid, argv[2][i]);
        }
        ft_send_bits(pid, '\n');
    }
    else
    {
        ft_printf("Some thing Wornng Please Try Agin!");
    }
    
    return (0);
}
