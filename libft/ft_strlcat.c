/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:23:32 by daykim            #+#    #+#             */
/*   Updated: 2022/01/26 19:33:22 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t			dest_len;
	size_t			src_len;
	size_t			index;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	if (n <= dest_len)
		return (n + src_len);
	while (*dest)
		dest++;
	n -= (dest_len + 1);
	index = 0;
	while ((index < n) && *(src + index))
	{
		*(dest + index) = *(src + index);
		index++;
	}
	*(dest + index) = '\0';
	return (dest_len + src_len);
}
