/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 07:49:08 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 07:51:37 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void			ft_count_arg(t_list *list, t_number *number)
{
	struct stat		infos;

	while (list)
	{
		if (lstat(list->value, &infos) == 0)
		{
			if (S_ISREG(infos.st_mode) || S_ISCHR(infos.st_mode)
				|| S_ISBLK(infos.st_mode) || S_ISLNK(infos.st_mode)
				|| S_ISSOCK(infos.st_mode) || S_ISFIFO(infos.st_mode))
				++number->files;
			else if (S_ISDIR(infos.st_mode))
			{
				list->valid = 1;
				++number->dir;
			}
		}
		else
		{
			list->valid = -1;
			++number->error;
		}
		list = list->next;
	}
}
