/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:30:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/03 13:02:08 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_d_list(t_dlist_check *li, int choice)
{
	t_dlistcell		*temporary;

	if (li == NULL)
		return ;
	if (choice)
	{
		temporary = li->begin;
		while (temporary && li->size_cell > 0)
		{
			printf("%s --> ", temporary->value);
			temporary = temporary->next;
		}
	}
	else
	{
		printf("INV : \n");
		temporary = li->end;
		while (temporary && li->size_cell > 0)
		{
			printf("%s --> ", temporary->value);
			temporary = temporary->prev;
		}
	}
	printf("NULL");
}
