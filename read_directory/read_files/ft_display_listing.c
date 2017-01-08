/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_listing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 08:57:09 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 18:14:00 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

static void		ft_write_law(long x)
{
	ft_putchar((S_ISFIFO(x)) ? 'p' : 0);
	ft_putchar((S_ISCHR(x)) ? 'c' : 0);
	ft_putchar((S_ISDIR(x)) ? 'd' : 0);
	ft_putchar((S_ISBLK(x)) ? 'b' : 0);
	ft_putchar((S_ISREG(x)) ? '-' : 0);
	ft_putchar((S_ISLNK(x)) ? 'l' : 0);
	ft_putchar((S_ISSOCK(x)) ? 's' : 0);
	ft_putstr((x & S_IRUSR) ? "r" : "-");
	ft_putstr((x & S_IWUSR) ? "w" : "-");
	if ((S_ISUID & x))
		ft_putchar((S_IXUSR & x) ? 's' : 'S');
	else
		ft_putstr((x & S_IXUSR) ? "x" : "-");
	ft_putstr((x & S_IRGRP) ? "r" : "-");
	ft_putstr((x & S_IWGRP) ? "w" : "-");
	if (S_ISGID & x)
		ft_putchar((S_IXGRP & x) ? 's' : 'S');
	else
		ft_putstr((x & S_IXGRP) ? "x" : "-");
	ft_putstr((x & S_IROTH) ? "r" : "-");
	ft_putstr((x & S_IWOTH) ? "w" : "-");
	if (S_ISVTX & x)
		ft_putchar((S_IXOTH & x) ? 't' : 'T');
	else
		ft_putstr((x & S_IXOTH) ? "x" : "-");
}

void			ft_minor_major(struct stat infos)
{
	if (ft_getlen_int(major(infos.st_rdev)) == 1)
		ft_putchar(' ');
	ft_putnbr(major(infos.st_rdev));
	ft_putchar(',');
	ft_putchar(' ');
	if (ft_getlen_int(minor(infos.st_rdev)) == 2)
		ft_putchar(' ');
	else if (ft_getlen_int(minor(infos.st_rdev)) == 1)
		ft_putstr("  ");
	ft_putnbr(minor(infos.st_rdev));
	ft_putchar(' ');
}

void			ft_display_listing(t_list *list)
{
	char			*str;
	struct stat		infos;
	t_infos			inf;

	inf = ft_get_infos(list);
	while (list)
	{
		lstat(list->value, &infos);
		str = ft_strrchr(list->value, '/');
		str = (str == NULL) ? list->value : ++str;
		ft_write_law(infos.st_mode);
		ft_print_link(infos.st_nlink, inf.size_nlink);
		ft_print_name(infos.st_uid, inf.size_name);
		ft_print_group(infos.st_gid, inf.size_group);
		if (S_ISCHR(infos.st_mode) || S_ISBLK(infos.st_mode))
			ft_minor_major(infos);
		else
			ft_print_octets(infos.st_size, inf.size_octets);
		ft_print_dated(ctime(&infos.st_mtime), infos.st_mtime);
		ft_putstr(str);
		if (S_ISLNK(infos.st_mode))
			ft_get_symbolique(list->value, infos.st_mode);
		list = list->next;
		ft_putchar('\n');
	}
}
