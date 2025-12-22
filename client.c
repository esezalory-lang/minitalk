/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esezalor <esezalor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:33:28 by esezalor          #+#    #+#             */
/*   Updated: 2025/12/22 15:41:38 by esezalor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int main(int argc, char **argv)
{
    if(argc != 3)
        return (0);
    send_signal(ft_atoi(argv[1]), argv[2]);
    return(0);
}

void send_signal(int pid, char *str)
{
    int j;
    int i;
    
    j = 0;
    while(str[j])
    {
        i = 0;
        while(i <= 7)
        {
            if((((unsigned char)str[j] << i) & 128) == 0)
            {
                kill(pid, SIGUSR2);
            }
            else
            {
                kill(pid, SIGUSR1);
            }
            usleep(500);
            i++;
        }
    j++;
    }
}