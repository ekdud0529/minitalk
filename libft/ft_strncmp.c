/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:02:27 by daykim            #+#    #+#             */
/*   Updated: 2022/01/27 22:16:33 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (!*(str1 + i) && !*(str2 + i))
			return (0);
		if (*(str1 + i) != *(str2 + i))
			return ((unsigned char)*(str1 + i) - (unsigned char)*(str2 + i));
		i++;
	}
	return (0);
}
