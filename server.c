/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:14 by imellali          #+#    #+#             */
/*   Updated: 2025/02/18 15:34:45 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	while (4)
	{
		printf("Server is running..\n");
		printf("Server PID : %d\n", getpid());
		pause();
	}
	return 0;
}
