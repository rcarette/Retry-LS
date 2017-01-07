/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 09:15:43 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 09:17:09 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		ft_lenght_list(t_list *list)
{
	int		size;

	size = 0;
	if (list == NULL)
		return (size);
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}
