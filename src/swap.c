/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:44:57 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/09 12:23:51 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_files(t_file *file_1, t_file *file_2)
{
	t_file	file_temp;

	file_temp = *file_1;
	*file_1 = *file_2;
	*file_2 = file_temp;
}
