/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:50:45 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/06 17:48:35 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_uint	get_res_size(t_uint value, int base)
{
	t_uint	size;

	size = 1;
	while (value / base)
	{
		value = value / base;
		size++;
	}
	return (size);
}

void	set_res(t_uint value, int base, char *res, t_uint res_size)
{
	t_uint		i;
	const char	*symbols = "0123456789abcdef";

	i = 0;
	while (value / base)
	{
		res[res_size - 1 - i] = symbols[value % base];
		value = value / base;
		i++;
	}
	res[res_size - 1 - i] = symbols[value % base];
}

char	*ft_itoa_base(t_uint value, int base)
{
	t_uint	res_size;
	char	*res;

	if (base >= 2 && base <= 16)
	{
		res_size = get_res_size(value, base);
		if (!(res = malloc(sizeof(char) * res_size)))
			return (NULL);
		res[res_size] = '\0';
		set_res(value, base, res, res_size);
		return (res);
	}
	return (NULL);
}
