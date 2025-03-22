/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:19:43 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/22 16:37:07 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler_signal(int signum)
{
	int	bit;
	char res;

	bit = 0;
	while(bit < 8)
	{
		res = res << 1;
		if (signum == SIGUSR1)
			res = res | 1;
		bit++;
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
