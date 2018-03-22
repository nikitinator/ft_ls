/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:53:33 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/21 18:57:14 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			file_list_to_arr(t_list *file_list, t_files *files)
{
	int		i;

	if (file_list)	
	{
		i = 0;
		if (!(files->arr = malloc(files->size * sizeof(t_file))))
			return ;
		while (file_list)
		{
			files->arr[i] = *(t_file *)file_list->content;
			i++;
			file_list = file_list->next;
		}
	}
}

void			dir_list_to_arr(t_list *dir_list, t_dirs *dirs)
{
	int		i;
	
	if (dir_list)	
	{
		i = 0;
		dirs->size = ft_list_count(dir_list);
		if (!(dirs->arr = malloc(dirs->size * sizeof(t_dir))))
			return ;
		while (dir_list)
		{
			dirs->arr[i] = *(t_dir *)dir_list->content;
			i++;
			dir_list = dir_list->next;
		}
	}
}
