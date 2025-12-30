/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezalory <sezalory@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:10:42 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/30 10:28:01 by sezalory         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// # define _POSIX_SOURCE
// # define _DEFAULT_SOURCE

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

// Client
void				confirmation(int signum);
void				send_signal(int pid, char *str);
void				send_char(int pid, unsigned char letter);

// Server
void				receiver(int signum, siginfo_t *info, void *context);

#endif