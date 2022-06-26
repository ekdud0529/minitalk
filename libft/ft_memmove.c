/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:21:26 by daykim            #+#    #+#             */
/*   Updated: 2022/01/18 15:48:30 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*s;
	unsigned char	*d;

	if (!dest && !src)
		return (0);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		index = 0;
		while (index < n)
		{
			*(d + index) = *(s + index);
			index++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			*(d + n) = *(s + n);
		}
	}
	return (dest);
}
