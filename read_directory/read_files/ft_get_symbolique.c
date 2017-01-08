/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_symbolique.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:48:47 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/08 18:16:33 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

void	ft_get_symbolique(char *name, int i)
{
	char	tab[256];

	ft_bzero(tab, 256);
	if (S_ISLNK(i))
	{
		if (readlink(name, tab, 256) != -1)
		{
			ft_putchar(' ');
			ft_putstr("-> ");
			ft_putstr(tab);
		}
		ft_bzero(tab, 256);
	}
}
