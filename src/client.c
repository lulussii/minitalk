/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:20:11 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/27 14:17:05 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_received_signal = 0;

void	handler_client(int signum)
{
	if (signum == SIGUSR1)
		g_received_signal = 1;
	else if (signum == SIGUSR2)
		ft_printf("Message reçu !\n");
}

void	send_bits(int pid, char c)
{
	int	bit;

	bit = 7;
	g_received_signal = 0;
	while (bit >= 0)
	{
		if (c & 1 << bit)
		{
			kill(pid, SIGUSR1);
			usleep(10000);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(10000);
		}
		while (!g_received_signal)
			pause();
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, handler_client);
	signal(SIGUSR2, handler_client);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Error : Wrong PID\n");
		return (1);
	}
	while (argv[2][i] != '\0')
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
