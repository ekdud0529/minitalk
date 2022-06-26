/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 19:24:35 by daykim            #+#    #+#             */
/*   Updated: 2022/01/18 15:46:45 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*find;
	int		index;

	find = 0;
	index = 0;
	while (*(str + index))
	{
		if (*(str + index) == (char)c)
		{
			find = ((char *)str + index);
		}
		index++;
	}
	if ((char)c == '\0')
		return ((char *)str + index);
	return (find);
}
