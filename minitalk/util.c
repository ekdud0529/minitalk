/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <daykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:36:38 by daykim            #+#    #+#             */
/*   Updated: 2022/06/27 16:36:38 by daykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_charjoin(char *s, char ch)
{
	size_t	s_len;
	size_t	index;
	char	*newstr;

	s_len = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * (s_len + 2));
	if (!newstr)
		return (0);
	index = 0;
	while (*s)
	{
		newstr[index] = *s;
		s++;
		index++;
	}
	newstr[index++] = ch;
	newstr[index] = '\0';
	free(s);
	return (newstr);
}