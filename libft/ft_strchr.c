/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:21:38 by daykim            #+#    #+#             */
/*   Updated: 2022/01/18 15:49:12 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (*(str + index))
	{
		if (*(str + index) == (char)c)
		{
			return ((char *)str + index);
		}
		index++;
	}
	if ((char)c == '\0')
		return ((char *)str + index);
	return (0);
}
