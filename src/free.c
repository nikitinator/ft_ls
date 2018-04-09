/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:37:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/09 11:59:18 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_files(t_files files)
{
	size_t	i;

	i = 0;
	if (files.arr)
		while (i < files.size)
		{
			free(files.arr[i].name);
			i++;
		}
	if (files.arr)
		free(files.arr);
}
