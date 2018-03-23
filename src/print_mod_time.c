/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mod_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:10:29 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 20:13:53 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_mod_time(time_t mod_time)
{
	char	*mod_time_str;
	time_t	cur_time;

	time(&cur_time);
	mod_time_str = ctime(&mod_time);
	mod_time_str[MONTH + 3] = '\0';
	ft_putstr(mod_time_str + MONTH);
	ft_putchar(' ');
	mod_time_str[DAY + 2] = '\0';
	ft_putstr(mod_time_str + DAY);
	ft_putchar(' ');
	if (cur_time - mod_time > 15768000)
	{
		ft_putchar(' ');
		mod_time_str[YEAR + 4] = '\0';
		ft_putstr(mod_time_str + YEAR);
	}
	else
	{
		mod_time_str[TIME + 5] = '\0';
		ft_putstr(mod_time_str + TIME);
	}
}
