/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:19:43 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/23 13:13:04 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_data	g_data = {0, 0};

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

int	main(int argc, char **argv)
{
	int	pid;

	pid = getpid();
	(void)argv;
	ft_printf("Serveur démarré. PID : %i\n", pid);
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (argc == 1)
		pause();
	return (0);
}
