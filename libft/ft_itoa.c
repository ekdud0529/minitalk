/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:16:04 by daykim            #+#    #+#             */
/*   Updated: 2022/01/23 15:14:54 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_num_len(long long n);
static void		mk_str(char *str, int len, long long num);

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long long	num;

	num = n;
	len = get_num_len(num);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	mk_str(str, len, num);
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	get_num_len(long long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	mk_str(char *str, int len, long long num)
{
	str[len] = '\0';
	if (num == 0)
	{
		str[len - 1] = 0 + '0';
	}
	else
	{
		while (num && len--)
		{
			str[len] = (num % 10) + '0';
			num /= 10;
		}
	}
}
