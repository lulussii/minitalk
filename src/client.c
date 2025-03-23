/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:20:11 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/23 13:16:51 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

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
	int pid;
	int i;

	i = 0;
	if (argc != 3)
		return (0);
	else
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_bits(pid, argv[2][i]);
			i++;	
		}
		send_bits(pid, '\0');
	}
}