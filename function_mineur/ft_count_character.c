/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:49:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 07:52:49 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int				ft_count_character(t_list *list)
{
	int		size;

	size = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->valid == 0)
			if (ft_strlen(list->value) > size)
				size = list->size_value;
		list = list->next;
	}
	return (size);
}
