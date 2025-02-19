/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:16:29 by imellali          #+#    #+#             */
/*   Updated: 2025/02/19 22:30:38 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signal)
{
    static unsigned char bits[8];
    static int index = 0;
    unsigned char char_byte;
    int i;

    if (signal == SIGUSR1)
        bits[index] = 0;
    else if (signal == SIGUSR2)
        bits[index] = 1;
    index++;
    if (index == 8)
    {
        char_byte = 0;
        i = 0;
        while (i < 8)
        {
            char_byte |= bits[i] << (7 - i);
            i++;
        }
        index = 0;
        ft_printf("%c", char_byte);
    }
}

int main(void)
{
    ft_printf("Server is Running..\nServer PID : %d\n", getpid());
    signal(SIGUSR1, sig_handler);
    while (1)
        pause();
    return (0);
}
