/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:16 by esezalor          #+#    #+#             */
/*   Updated: 2026/01/15 17:28:06 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_message[1000000000];

void	write_and_kill(char *str, int signum, siginfo_t *info)
{
	int	i;

	i = 0;
	kill(info->si_pid, signum);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	complete_bite(char character, siginfo_t *info)
{
	static int	i;

	g_message[i] = character;
	if (character == '\0')
	{
		write_and_kill(g_message, SIGUSR2, info);
		i = 0;
	}
	else
	{
		kill(info->si_pid, SIGUSR1);
		i++;
	}
}

void	receiver(int signum, siginfo_t *info, void *context)
{
	static char	track_char;
	static int	bit_count;

	(void)context;
	if (bit_count < 8)
	{
		track_char = track_char << 1;
		if (signum == SIGUSR1)
			track_char += 1;
		bit_count++;
	}
	if (bit_count == 8)
	{
		complete_bite(track_char, info);
		track_char = 0;
		bit_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	configure_s;

	configure_s.sa_sigaction = &receiver;
	configure_s.sa_flags = SA_SIGINFO;
	sigemptyset(&configure_s.sa_mask);
	sigaction(SIGUSR1, &configure_s, NULL);
	sigaction(SIGUSR2, &configure_s, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
