/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:42:34 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 14:36:23 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	reverse_files(t_files files)
{
	int		i; //prover type

	i = 0;
	while (i < files.size / 2)
	{
		swap_files(files.arr + i, files.arr + (files.size - i - 1));
		i++;
	}
}
