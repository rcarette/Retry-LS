/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:10:06 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/06 19:37:45 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_clear_list(t_list **list)
{
	t_list		*delete;
	while (*list)
	{
		delete = (*list);
		(*list) = (*list)->next;
		free(delete->value);
		free(delete);
	}
}
