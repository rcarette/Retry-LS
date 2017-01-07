/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_new_cell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 22:21:33 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/06 15:20:04 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list			*new_list(void)
{
	return (NULL);
}

t_list			*creat_new_cell(char *data, int size_value,
					time_t date_value, int valid)
{
	t_list		*new_elem;

	if (!(new_elem = (t_list *)malloc(sizeof(t_list))))
		exit(EXIT_FAILURE);
	if (!(new_elem->value = (char *)malloc(sizeof(char) *
					(ft_strlen(data) + 1))))
		exit(EXIT_FAILURE);
	ft_memcpy(new_elem->value, data, (ft_strlen(data) + 1));
	new_elem->next = NULL;
	new_elem->size_value = size_value;
	new_elem->date_value = date_value;
	new_elem->valid = valid;
	return (new_elem);
}
