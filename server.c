/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:14 by imellali          #+#    #+#             */
/*   Updated: 2025/02/19 22:57:15 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char bits[8];
	static int index = 0;
	unsigned char char_byte;
	int i;

	(void)context;
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
		if (char_byte != '\0')
			ft_printf("%c", char_byte);
		else
			kill(info->si_pid, SIGUSR1);
	}
}

void print_banner(void)
{
	ft_printf("\033[1;32m");
	ft_printf("\n");
	ft_printf("   ██████ ███████ ██████  ██    ██ ███████ ██████   \n");
	ft_printf("  ██      ██      ██   ██ ██    ██ ██      ██   ██  \n");
	ft_printf("   █████  █████   ██████  ██    ██ █████   ██████   \n");
	ft_printf("       ██ ██      ██   ██  ██  ██  ██      ██   ██  \n");
	ft_printf("  ██████  ███████ ██   ██   ████   ███████ ██   ██  \n");
	ft_printf("\033[0m\n");
	ft_printf("\033[1;36m──────────────────────────────────────────────────\033[0m\n");
	ft_printf("\033[1;33m\033[5m");
	ft_printf("  ➤ Server is Running...\n");
	ft_printf("\033[0m");
	ft_printf("\033[1;34m\033[4m");
	ft_printf("  ➤ Server PID : %d\n", getpid());
	ft_printf("\033[0m");
	ft_printf("\033[1;36m──────────────────────────────────────────────────\033[0m\n");
}

int main(void)
{
	struct sigaction sig;

	print_banner();
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
