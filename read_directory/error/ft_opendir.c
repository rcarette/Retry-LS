/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opendir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 08:21:38 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/07 08:24:48 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_ls.h"

DIR		*ft_opendir(char *name)
{
	DIR		*rep;

	if (!(rep = opendir(name)))
		return (NULL);
	return (rep);
}

void	ft_display(char *name)
{
		ft_putstr(name);
		ft_putendl(":");
}

