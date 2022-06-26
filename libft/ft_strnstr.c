/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:35:33 by daykim            #+#    #+#             */
/*   Updated: 2022/01/18 15:42:51 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	index;
	size_t	start;

	if (!(*substr))
		return ((char *)str);
	index = 0;
	while (*(str + index) && (index < n))
	{
		start = 0;
		while (str[index + start] && substr[start] && (index + start < n))
		{
			if (str[index + start] != substr[start])
				break ;
			start++;
		}
		if (!substr[start])
			return ((char *)(str + index));
		index++;
	}
	return (0);
}
