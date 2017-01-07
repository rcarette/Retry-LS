/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_bulle_dlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 07:51:57 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/06 14:45:12 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_swap(void *s1, void *s2, int size)
{
	char	temporary;
	int		i;

	i = -1;
	while (++i < size)
	{
		temporary = ((char *)s1)[i];
		((char *)s1)[i] = ((char *)s2)[i];
		((char *)s2)[i] = temporary;
	}
}

void			ft_tri_bulle_dlist_sort_time(t_list **li)
{
	t_list		*t;
	int				permmut;
	t_list		*temporary;

	permmut = 1;
	if (!(*li))
		return ;
	t = (*li);
	while (permmut)
	{
		permmut = 0;
		while (t->next)
		{
			if (t->date_value < t->next->date_value)
			{
				permmut = 1;
				ft_swap(&t->value, &t->next->value, sizeof(char *));
				ft_swap(&t->date_value, &t->next->date_value, sizeof(time_t));
				ft_swap(&t->size_value, &t->next->size_value, sizeof(int));
				ft_swap(&t->valid, &t->next->valid, sizeof(int));
			}
			else if (t->date_value == t->next->date_value
					&& ft_strcmp(t->value, t->next->value) > 0)
			{
				permmut = 1;
				ft_swap(&t->value, &t->next->value, sizeof(char *));
				ft_swap(&t->date_value, &t->next->date_value, sizeof(time_t));
				ft_swap(&t->size_value, &t->next->size_value, sizeof(int));
				ft_swap(&t->valid, &t->next->valid, sizeof(int));
			}
			t = t->next;
		}
		t = (*li);
	}
}

void			ft_tri_bulle_dlist_sort_ascii(t_list **li)
{
	t_list		*t;
	int				permmut;

	permmut = 1;
	if (!(*li))
		return ;
	t = (*li);
	while (permmut)
	{
		permmut = 0;
		while (t->next)
		{
			if (strcmp(t->value, t->next->value) > 0)
			{
				permmut = 1;
				ft_swap(&t->value, &t->next->value, sizeof(char *));
				ft_swap(&t->size_value, &t->next->size_value, sizeof(int));
				ft_swap(&t->date_value, &t->next->date_value, sizeof(time_t));
				ft_swap(&t->valid, &t->next->valid, sizeof(int));
			}
			t = t->next;
		}
		t = (*li);
	}
}
