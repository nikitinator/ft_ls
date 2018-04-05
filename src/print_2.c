/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:21:17 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/05 19:24:30 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_n_spaces(int n)
{
	while (n-- > 0)
		ft_putchar(' ');
}

//void	print_mod_time(time_t mod_time)
//{
//	char	*mod_time_str;
//	time_t	cur_time;
//
//	time(&cur_time);
//	mod_time_str = ctime(&mod_time);
//	mod_time_str[MONTH + 3] = '\0';
//	ft_putstr(mod_time_str + MONTH);
//	ft_putchar(' ');
//	mod_time_str[DAY + 2] = '\0';
//	ft_putstr(mod_time_str + DAY);
//	ft_putchar(' ');
//	if (ABS(cur_time - mod_time) > HALF_YEAR)
//	{
//		ft_putchar(' ');
//		*ft_strrchr(mod_time_str + YEAR, '\n') = '\0';
//		mod_time_str += YEAR;
//		while (ft_iswhsp(*mod_time_str) && *mod_time_str)
//			mod_time_str++;
//		ft_putstr(mod_time_str);
//	}
//	else
//	{
//		mod_time_str[TIME + 5] = '\0';
//		ft_putstr(mod_time_str + TIME);
//	}
//}

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
	if (ABS(cur_time - mod_time) > HALF_YEAR)
	{
		ft_putchar(' ');
		*ft_strrchr(mod_time_str + YEAR, '\n') = '\0';
		mod_time_str += YEAR;
		while (ft_iswhsp(*mod_time_str) && *mod_time_str)
			mod_time_str++;
		ft_putstr(mod_time_str);
	}
	else
	{
		mod_time_str[TIME + 5] = '\0';
		ft_putstr(mod_time_str + TIME);
	}
}

void	putnbr_align(int n, t_byte num_space)
{
	print_n_spaces(num_space);
	ft_putnbr(n);
}

void	putstr_align(char *str, t_byte num_space)
{
	ft_putstr(str);
	print_n_spaces(num_space);
}
