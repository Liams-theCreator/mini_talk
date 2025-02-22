/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:14 by imellali          #+#    #+#             */
/*   Updated: 2025/02/22 16:46:34 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signal)
{
	static unsigned char	bits[8];
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
		index = 0;
		ft_printf("%c", char_byte);
	}
}

static void	print_banner(void)
{
	ft_printf("\033[1;94m");
	ft_printf("\n");
	ft_printf("   ██████ ███████ ██████  ██    ██ ███████ ██████   \n");
	ft_printf("  ██      ██      ██   ██ ██    ██ ██      ██   ██  \n");
	ft_printf("   █████  █████   ██████  ██    ██ █████   ██████   \n");
	ft_printf("       ██ ██      ██   ██  ██  ██  ██      ██   ██  \n");
	ft_printf("  ██████  ███████ ██   ██   ████   ███████ ██   ██  \n");
	ft_printf("\033[0m\n");
	ft_printf("\033[1;36m───────────────────────────────────\033[0m\n");
	ft_printf("\033[1;92m\033[5m");
	ft_printf("  ➤ Server is Running...\n");
	ft_printf("\033[0m");
	ft_printf("\033[1;93m");
	ft_printf("  ➤ Server PID : %d\n", getpid());
	ft_printf("\033[0m");
	ft_printf("\033[1;36m───────────────────────────────────\033[0m\n");
}

int	main(void)
{
	print_banner();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
