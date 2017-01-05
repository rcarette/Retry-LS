/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:26:36 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/04 12:42:57 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			choice_push_data(t_dlist_check **li,
					t_dlistcell **new, int choice)
{
	if (choice)
	{
		(*li)->begin->prev = (*new);
		(*new)->next = (*li)->begin;
		(*li)->begin = (*new);
	}
	else
	{
		(*li)->end->next = *new;
		(*new)->prev = (*li)->end;
		(*li)->end = (*new);
	}
	(*li)->size_cell += 1;
}

t_dlist_check		*push_data(t_dlist_check *li, t_data *data, int choice)
{
	t_dlistcell		*new_elem;

	new_elem = creat_new_cell(data->value, data->size_value, data->date_value,
			data->valid);
	if (is_empty_dlist(li))
	{
		if (!(li = (t_dlist_check *)malloc(sizeof(*li))))
			exit(EXIT_FAILURE);
		li->size_cell = 1;
		li->begin = new_elem;
		li->end = new_elem;
		return (li);
	}
	choice_push_data(&li, &new_elem, choice);
	return (li);
}
