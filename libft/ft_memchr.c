/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:27:08 by daykim            #+#    #+#             */
/*   Updated: 2022/01/18 15:46:29 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			index;
	unsigned char	*s;

	s = (unsigned char *)str;
	index = 0;
	while (index < n)
	{
		if (*(s + index) == (unsigned char)c)
		{
			return ((void *)(s + index));
		}
		index++;
	}
	return (0);
}
