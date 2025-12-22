/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:10:42 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/22 15:42:15 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_SOURCE
# define _DEFAULT_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
# include "libft/libft.h"

// Client
void send_signal(int pid, char *str);

// Server


#endif