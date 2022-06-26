/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:21:58 by daykim            #+#    #+#             */
/*   Updated: 2022/01/18 15:48:37 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src)
		return (dest);
	index = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (index < n)
	{
		*(d + index) = *(s + index);
		index++;
	}
	return (dest);
}
