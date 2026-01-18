/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:10:42 by esezalor          #+#    #+#             */
/*   Updated: 2026/01/18 21:35:37 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_SOURCE
# define _DEFAULT_SOURCE

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// Client
void	confirmation(int signum);
void	send_signal(int pid, char *str);
void	send_char(int pid, unsigned char letter);

// Server
void	receiver(int signum, siginfo_t *info, void *context);
void	complete_bite(char character, siginfo_t *info);
void	write_and_kill(char *str, int signum, siginfo_t *info);

#endif