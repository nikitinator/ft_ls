/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:53:33 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/28 11:32:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			file_list_to_arr(t_list *file_list, t_files *files)
{
	int		i;

	if (file_list)
	{
		i = 0;
		files->size = ft_list_count(file_list);
		if (!(files->arr = malloc(files->size * sizeof(t_file))))
			return ;
		while (file_list)
		{
			files->arr[i] = *(t_file *)file_list->content;
			file_list = file_list->next;
			i++;
		}
	}
}
