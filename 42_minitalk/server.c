/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:51:34 by tschmidt          #+#    #+#             */
/*   Updated: 2022/01/16 13:51:42 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void	handle_incoming_message(int signo, siginfo_t *sender_sig, void *context)
{
	static unsigned int	c = 0;
	static unsigned int	mask = 0b10000000;

	if (signo == SIGUSR1)
		c += mask;
	kill(sender_sig->si_pid, SIGUSR1);
	mask >>= 1;
	if (!mask)
	{
		write(1, &c, 1);
		if (c == 0)
			kill(sender_sig->si_pid, SIGUSR2);
		c = 0;
		mask = 0b10000000;
	}
	(void) context;
}

int	main(void)
{
	struct sigaction	s_server_action;

	ft_printf("\nThis is the server's PID: %d\nUse this to send it a message!\n",
		getpid());
	s_server_action.sa_flags = SA_SIGINFO;
	s_server_action.sa_sigaction = handle_incoming_message;
	sigaction(SIGUSR1, &s_server_action, NULL);
	sigaction(SIGUSR2, &s_server_action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
