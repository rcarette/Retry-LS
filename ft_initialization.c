/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 13:23:23 by rcarette          #+#    #+#             */
/*   Updated: 2017/01/04 16:53:23 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt		ft_initialization_opt(void)
{
	t_opt		option;

	option.reverse = 0;
	option.date_sort = 0;
	option.upper_r = 0;
	option.listing = 0;
	option.file_hide = 0;
	option.i_param = 0;
	option.number_opt = 0;
	return (option);
}

void		ft_init_data(t_data **data, char *value,
		time_t date_value, int size_value)
{
	if (!(*data = (t_data *)malloc(sizeof(t_data))))
		exit(EXIT_FAILURE);
	if (!((*data)->value = (char *)malloc(sizeof(char) * size_value)))
		exit(EXIT_FAILURE);
	ft_memcpy((*data)->value, value, size_value);
	(*data)->date_value = date_value;
	(*data)->size_value = size_value;
	(*data)->valid = 0;
}

t_number	ft_initialization_number(void)
{
	t_number	number;

	number.error = 0;
	number.files = 0;
	number.dir = 0;
	return (number);
}
