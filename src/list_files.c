/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:55:51 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/05 18:10:12 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h" 

void	print_files(t_files files)
{
	size_t	i;

	i = 0;
	while (i < files.size)
	{
		ft_putendl(files.arr[i].name);
		i++;
	}
}

void	list_files(t_files files, char *dir_path, t_params params)
{
	if (!files.size)
		return ;
	sort_files(files, params.time_modif);
	if (params.reverse)
		reverse_files(files);
	if (params.long_format)
		print_files_long(files, dir_path);
	else
		print_files(files);
//	if (dir_path)
//		free(dir_path);
}
