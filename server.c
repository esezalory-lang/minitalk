/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezalory <sezalory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:16 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/30 10:29:02 by sezalory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		write(1, &track_char, 1);
		if (track_char == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			write(1, "\n", 1);
		}
		else
			kill(info->si_pid, SIGUSR1);
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
