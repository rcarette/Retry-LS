/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:44:23 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 16:42:20 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		ft_listdup(t_list **list, t_list **new_list)
{
	t_list			*temporary;
	struct stat		infos;
	t_data			*data;

	temporary = *list;
	while (temporary)
	{
		if (temporary->valid == 1)
		{
			stat(temporary->value, &infos);
			ft_init_data(&data, temporary->value, infos.st_mtime,
				(ft_strlen(temporary->value) + 1));
			push_data(new_list, data);
			free(data->value);
			free(data);
		}
		temporary = temporary->next;
	}
	ft_clear_list(list);
	*list = *new_list;
}
