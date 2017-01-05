/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_dlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:52:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/04 10:29:28 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dlist_check	*ft_clear_dlists(t_dlist_check **li)
{
	t_dlistcell		*temporary;
	t_dlistcell		*delete;

	if (*li == NULL)
		return (new_dlist());
	temporary = (*li)->begin;
	while (temporary)
	{
		delete = temporary;
		temporary = temporary->next;
		free(delete->value);
		free(delete);
	}
	free(*li);
	return (new_dlist());
}
