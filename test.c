/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:58:44 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/23 13:09:48 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

t_data  g_data = {0,0};

void	handler_signal(int signum)
{
	if (signum == SIGUSR1)
		g_data.c |= (1 << (7 - g_data.bit_index));
	g_data.bit_index++;
	if (g_data.bit_index == 8)
	{
		if (g_data.c == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_data.c, 1);
		g_data.bit_index = 0;
		g_data.c = 0;	
	}
}

void send_bits(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c & 1 << bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (100);
		bit--;
	}
}

int main(int argc, char **argv)
{
	handler_signal(SIGUSR2);
	handler_signal(SIGUSR1);
	handler_signal(SIGUSR2);
	handler_signal(SIGUSR1);
	handler_signal(SIGUSR1);
	handler_signal(SIGUSR1);
	handler_signal(SIGUSR1);
	handler_signal(SIGUSR2);
}