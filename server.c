/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:09:08 by daykim            #+#    #+#             */
/*   Updated: 2022/06/26 16:09:08 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server()
{
	struct sigaction	sig;

	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) != 0)
	{
		ft_putstr_fd("SIGUSR1 Error", 1);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sig, NULL) != 0)
	{
		ft_putstr_fd("SIGUSR2 Error", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		ft_putstr_fd("Error argument count", 1);
	}

	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd("\n", 1);

	ft_server();

	while (1)
	{
		pause();
	}
	return (0);
}