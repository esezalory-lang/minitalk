/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezalory <sezalory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:16 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/28 19:38:38 by sezalory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// 1. Print server PID on launch

// 3. sigaction struct to handle SIGUSR1 and SIGUSR2 signals without termintating

// 4. Configure struct sigaction to use sa_sigaction field and set SA_SIGINFO flag

// 5. void handler(int signum, siginfo_t *info, void *context);
// - signum: signal number received (SIGUSR1 or SIGUSR2)
// - info: pointer to siginfo_t structure with PID

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	track_char;
	static int	bit_count;

	if (bit_count < 8)
	{
		track_char = track_char << 1;
		if (signum == SIGUSR2)
			track_char += 1;
		bit_count++;
	}
	if (bit_count == 8)
	{
		write(1, &track_char, 1);
		bit_count = 0;
        track_char = 0;
	}
}

int	main(void)
{
	struct sigaction configure;

	configure.sa_sigaction = &signal_handler;
	configure.sa_flags = SA_SIGINFO;
	sigemptyset(&configure.sa_mask);
	
    ft_printf("Server PID: %d\n", getpid());
    sigaction(SIGUSR1, &configure, NULL);
    sigaction(SIGUSR2, &configure, NULL);
    while (1)
    {   
        pause();
    }
    return (0);
}