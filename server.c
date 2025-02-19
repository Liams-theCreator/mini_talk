/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:14 by imellali          #+#    #+#             */
/*   Updated: 2025/02/19 16:39:44 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned	char	bits[8];
	static int				index = 0;
	unsigned char			char_byte;
	int						i;

	(void)context;
	(void)info;
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
	struct sigaction sa;
	ft_printf("Server is Running..\nServer PID : %d\n", getpid());
	
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return 0;
}
