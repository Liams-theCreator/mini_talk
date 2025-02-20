/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:16:16 by imellali          #+#    #+#             */
/*   Updated: 2025/02/19 22:29:58 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*convert_to_bin(char byte)
{
	int		i;
	int		j;
	char	bin[9];

	i = 7;
	j = 0;
	while (i >= 0 && j < 8)
	{
		bin[j] = ((byte >> i) & 1) + '0';
		j++;
		i--;
	}
	bin[8] = '\0';
	return (ft_strdup(bin));
}

static void	sig_back_handler(int sigint)
{
	(void)sigint;
	ft_printf("MESSAGE FROM SERVER : DONE.\n");
	exit(0);
}

static void	send_signal(char *message, int pid)
{
	int		i;
	int		j;
	char	*bin;

	i = 0;
	while (message[i])
	{
		bin = convert_to_bin(message[i]);
		if (!bin)
			exit(-1);
		j = 0;
		while (bin[j])
		{
			if (bin[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(250);
			j++;
		}
		free(bin);
		i++;
	}
}

static void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(150);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc < 3)
		return (-1);
	pid = ft_atoi(argv[2]);
	if (pid < 0)
		return (-1);
	message = argv[1];
	signal(SIGUSR1, sig_back_handler);
	send_signal(message, pid);
	send_null(pid);
	pause();
	return (0);
}