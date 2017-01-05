/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_dcell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 06:59:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/03 12:51:57 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_clear_dcell(t_dlist_check **li)
{
	t_dlistcell		*temporary;

	if (*li == NULL)
		return ;
	else if ((*li)->size_cell == 0)
	{
		free(*li);
		*li = new_dlist();
		return ;
	}
	temporary = (*li)->begin;
	(*li)->begin = temporary->next;
	(*li)->size_cell--;
	free(temporary->value);
	free(temporary);
}
