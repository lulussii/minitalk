/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:14:25 by lserodon          #+#    #+#             */
/*   Updated: 2025/03/25 16:54:52 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* ----- LIBRARIES ----- */

# include "../libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

/* ----- STRUCTURE ----- */

typedef struct s_data
{
	char	c;
	int		bit_index;
}				t_data;

/* ----- SERVER.C ----- */
void	handler_signal(int signum, siginfo_t *info, void *context);

/* ----- CLIENT.C ----- */
void	send_bits(int pid, char c);

#endif