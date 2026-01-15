/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:28 by esezalor          #+#    #+#             */
/*   Updated: 2026/01/15 17:28:12 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_signal_received;

int	main(int argc, char **argv)
{
	struct sigaction	configure_c;

	configure_c.sa_handler = &confirmation;
	configure_c.sa_flags = 0;
	sigemptyset(&configure_c.sa_mask);
	if (argc != 3)
		return (ft_printf("Wrong Number of Arguments"), 0);
	sigaction(SIGUSR1, &configure_c, NULL);
	sigaction(SIGUSR2, &configure_c, NULL);
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}

void	confirmation(int signum)
{
	g_signal_received = 1;
	if (signum == SIGUSR2)
		exit(0);
}

void	send_signal(int pid, char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		send_char(pid, (unsigned char)str[j]);
		j++;
	}
	send_char(pid, 0);
}

void	send_char(int pid, unsigned char letter)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		g_signal_received = 0;
		if (((letter << i) & 128) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_signal_received == 0)
			pause();
		i++;
	}
}
