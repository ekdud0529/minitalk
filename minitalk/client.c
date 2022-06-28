/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:09:05 by daykim            #+#    #+#             */
/*   Updated: 2022/06/26 16:09:05 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int c)
{
	if (c == 1)
	{
		kill(pid, SIGUSR1);
	}
	else if (c == 0)
	{
		kill(pid, SIGUSR2);
	}
	usleep(1000);
}

void	char_to_bit(int pid, int c)
{
	int	index;

	index = 7;
	while (index--)
	{
		if ((c & (1 << index)) == 0)
			send_bit(pid, 0);
		else
			send_bit(pid, 1);
	}
	usleep(100);
}

void	ft_client(int pid, char *msg)
{
	int	index;

	index = 0;
	while (msg[index])
	{
		char_to_bit(pid, msg[index]);
		index++;
	}
	index = 7;
	while (index--)
	{
		send_bit(pid, 0);
	}
	ft_putstr_fd("Sent to MSG\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Error client argc\n", 1);
		exit(1);
	}
	ft_putstr_fd("Client PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	ft_client(ft_atoi(argv[1]), argv[2]);
	return (0);
}
