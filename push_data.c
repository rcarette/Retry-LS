/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:26:36 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/06 14:36:59 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_is_empty_list(t_list *list)
{
	if (list == NULL)
		return (1);
	return (0);
}

void		push_data(t_list **li, t_data *data)
{
	t_list		*new_elem;
	t_list		*temporary;

	new_elem = creat_new_cell(data->value, data->size_value, data->date_value,
			data->valid);
	if (ft_is_empty_list(*li))
	{
		*li = new_elem;
		return ;
	}
	temporary = (*li);
	while (temporary->next)
		temporary = temporary->next;
	temporary->next = new_elem;
}
