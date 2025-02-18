/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:44 by imellali          #+#    #+#             */
/*   Updated: 2025/02/18 17:55:52 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*convert_to_bin(char byte)
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

int main(int argc, char **argv)
{
	char	*message;
	char	*bin;
	int		pid;
	int		i;
	int		j;

	if (argc < 3)
		return (-1);

	pid = ft_atoi(argv[2]);
	if (pid <= 2)
		return (-1);

	message = argv[1];
	i = 0;
	while (message[i])
	{
		bin = convert_to_bin(message[i]);
		if (!bin)
			return (-1);
		j = 0;
		while (bin[j])
		{
			if (bin[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		free(bin);
		i++;
	}
	return 0;
}
