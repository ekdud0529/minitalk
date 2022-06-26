/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:51:50 by daykim            #+#    #+#             */
/*   Updated: 2022/01/25 19:02:13 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			nums[10];
	long long	num;
	int			index;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	index = 0;
	if (num == 0)
		nums[index++] = 0;
	while (num)
	{
		nums[index++] = num % 10;
		num /= 10;
	}
	while (index--)
	{
		ft_putchar_fd((nums[index] + '0'), fd);
	}
}
