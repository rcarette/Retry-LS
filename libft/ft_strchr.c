/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 16:58:56 by rcarette          #+#    #+#             */
/*   Updated: 2016/11/04 19:28:54 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*s1;

	i = 0;
	s1 = (char *)s;
	while (i < ft_strlen(s) + 1)
	{
		if (*s1 == (char)c)
			return (s1);
		s1++;
		i++;
	}
	return (NULL);
}
