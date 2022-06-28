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

static char	*g_msg;

char	*ft_charjoin(char *s, char ch)
{
	size_t	s_len;
	size_t	index;
	char	*newstr;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!newstr)
		return (0);
	index = 0;
	while (s[index])
	{
		newstr[index] = s[index];
		index++;
	}
	newstr[index++] = ch;
	newstr[index] = '\0';
	free(s);
	return (newstr);
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static char	ch = '\0';
	static int	index = 8;

	(void)context;
	if (signum == SIGUSR1)
		ch |= (1 << --index);
	else if (signum == SIGUSR2)
		--index;
	if (index == 0)
	{
		if (ch == '\0')
		{
			ft_putnbr_fd(info->si_pid, 1);
			ft_putstr_fd(" : ", 1);
			ft_putstr_fd(g_msg, 1);
			ft_putchar_fd('\n', 1);
			free(g_msg);
			g_msg = ft_strdup("");
		}
		else
			g_msg = ft_charjoin(g_msg, ch);
		index = 8;
		ch = '\0';
	}
}

static void	ft_server(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) != 0)
	{
		ft_putstr_fd("SIGUSR1 sigaction Error", 1);
		exit(1);
	}
	if (sigaction(SIGUSR2, &sig, NULL) != 0)
	{
		ft_putstr_fd("SIGUSR2 sigaction Error", 1);
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
	g_msg = ft_strdup("");
	while (1)
		pause();
	return (0);
}
