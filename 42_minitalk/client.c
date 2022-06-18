/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmidt <tschmidt@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:28:29 by tschmidt          #+#    #+#             */
/*   Updated: 2022/01/16 13:32:05 by tschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	conv;

	neg = 0;
	i = 0;
	conv = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		conv = (str[i] - 48) + (10 * conv);
		i++;
	}
	if (neg == 1)
		conv = conv * -1;
	return (conv);
}

void	handle_server_response(int signo)
{
	if (signo == SIGUSR1)
		usleep(500);
	if (signo != SIGUSR1)
		ft_printf("Your message was received!\n");
}

void	send_char(pid_t pid, unsigned char message_char)
{
	unsigned char	mask;

	mask = 0b10000000;
	while (mask)
	{
		if (message_char & mask)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		mask >>= 1;
	}
}

void	handle_message_to_send(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	s_server_response;
	pid_t				pid;

	if (argc != 3)
	{
		ft_printf("Please try again with a valid PID and a message.\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
	{
		ft_printf("Please try again with a valid PID!\n");
		return (1);
	}
	s_server_response.sa_handler = handle_server_response;
	s_server_response.sa_flags = 0;
	sigaction(SIGUSR1, &s_server_response, NULL);
	sigaction(SIGUSR2, &s_server_response, NULL);
	handle_message_to_send(pid, argv[2]);
	return (0);
}
