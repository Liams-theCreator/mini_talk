/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:14 by imellali          #+#    #+#             */
/*   Updated: 2025/02/19 13:46:17 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal)
{
	static unsigned	char	bits[8];
	static int				index = 0;
	unsigned char			char_byte;
	int						i;

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
		ft_printf("%c", char_byte);
		index = 0;
	}
}

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server is Running..\nServer PID : %d\n", pid);
	
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return 0;
}
