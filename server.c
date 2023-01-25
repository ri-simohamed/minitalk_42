/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:15:31 by mrami             #+#    #+#             */
/*   Updated: 2023/01/24 22:42:41 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>

static void ft_handle_bit(int sgl)
{
    static int bit;
    static int c;

    if (sgl == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", c);
        bit = 0;
        c = 0;
    }
}

int main(int argc, char const *argv[])
{
    int pid;
    
    pid = getpid();
    ft_printf("Server PID -> %d", pid);
    
    signal(SIGUSR1, ft_handle_bit);
    signal(SIGUSR2, ft_handle_bit);
    if (argc > 1)
        return;
    while (1)
    {
        pause();
    }
    
    return (0);
}
