/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_line_total.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 09:10:04 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 10:03:13 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

static void		ft_display_totals(int totals)
{
	ft_putstr("\033[31m");
	ft_putstr("total ");
	ft_putnbr(totals);
	ft_putchar('\n');
	ft_putstr("\033[0m");
}

void			ft_count_line_total(char *name, t_opt opt, int totals)
{
	struct dirent	*current;
	struct stat		infos;
	char			*str;
	int				i;
	DIR				*rep;

	i = 0;
	rep = ft_opendir(name);
	while ((current = readdir(rep)))
	{
		++i;
		str = ft_insert_slash(name, current->d_name);
		lstat(str, &infos);
		if (opt.file_hide == 1 || current->d_name[0] != '.')
			totals += infos.st_blocks;
		if ((ft_strcmp(current->d_name, ".") == 0
				|| ft_strcmp(current->d_name, "..") == 0) && opt.file_hide == 0)
			--i;
		free(str);
	}
	closedir(rep);
	if (i > 0)
		ft_display_totals(totals);
}
