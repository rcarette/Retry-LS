/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:37:49 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 07:38:43 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			ft_display_error(t_list *list)
{
	while (list)
	{
		if (list->valid == -1)
		{
			ft_putstr("ft_ls: ");
			perror(list->value);
		}
		list = list->next;
	}
}
