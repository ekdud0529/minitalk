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

static char	*msg;

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	ch = '\0';
	static int	index = 7;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		ch |= (1 << index--);
	else if(signum == SIGUSR2)
		index--;
	if (index == 0)
	{
		if(ch == '\0')
		{
			ft_putstr_fd(msg, 1);
			free(msg);
		}
		else
			msg = ft_charjoin(msg, ch);
		index = 7;
		ch = '\0';
	}
}

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

int	main(int argc, char *argv[])
{
	if (argc != 1)
	{
		ft_putstr_fd("Error ", 1);
		ft_putstr_fd(argv[0], 1);
		ft_putchar_fd('\n', 1);
		exit(1);
	}

	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);

	ft_server();

	while (1)
		pause();
	return (0);
}
