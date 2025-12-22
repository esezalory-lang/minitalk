/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:16 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/22 15:55:44 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// 1. Print server PID on launch

// 3. sigaction struct to handle SIGUSR1 and SIGUSR2 signals without termintating

// 4. Configure struct sigaction to use sa_sigaction field and set SA_SIGINFO flag

// 5. void handler(int signum, siginfo_t *info, void *context);
// - signum: signal number received (SIGUSR1 or SIGUSR2)
// - info: pointer to siginfo_t structure with PID



void signal_handler(int signum)
{
    static char c;
    int bit_count;
    
    
}

int main(void)
{
    struct sigaction configure;
    
    configure.sa_sigaction = &signal_handler;
    configure.sa_flags = SA_SIGINFO;
    sigemptyset(&configure.sa_mask);
    sigaction()

    ft_printf("Server PID: %d\n", getpid());
}