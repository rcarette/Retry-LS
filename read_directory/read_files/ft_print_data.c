/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:52:26 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 18:15:50 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	ft_print_link(int nlink, int size)
{
	int		i;

	i = 0;
	ft_putstr("  ");
	i = ft_getlen_int(nlink);
	size = (size - i);
	while (size--)
		ft_putchar(' ');
	ft_putnbr(nlink);
}

void	ft_print_name(int uid, int size)
{
	struct passwd	*name;
	int				size_current;

	ft_putchar(' ');
	name = getpwuid(uid);
	size_current = ft_strlen(name->pw_name);
	ft_putstr(name->pw_name);
	size = (size - size_current) + 2;
	while (size--)
		ft_putchar(' ');
}

void	ft_print_group(int gid, int size)
{
	int				i;
	struct group	*group;

	group = getgrgid(gid);
	size = (size - ft_strlen(group->gr_name));
	ft_putstr(group->gr_name);
	while (size--)
		ft_putchar(' ');
}

void	ft_print_octets(int octets, int size)
{
	int		i;

	ft_putstr("  ");
	i = ft_getlen_int(octets);
	size = (size - i);
	while (size--)
		ft_putchar(' ');
	ft_putnbr(octets);
	ft_putstr(" ");
}

void	ft_print_dated(char *dated, time_t date)
{
	char		*s1;
	time_t		now;

	now = time(NULL);
	now -= date;
	if (now < 15778800)
	{
		s1 = ft_strsub(dated, 4, 12);
		ft_putstr(s1);
		free(s1);
		ft_putstr(" ");
	}
	else
	{
		write(1, dated + 4, 7);
		ft_putchar(' ');
		write(1, dated + 20, 4);
		ft_putchar(' ');
	}
}
