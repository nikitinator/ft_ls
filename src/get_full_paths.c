/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 20:27:17 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/05 18:51:02 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*append_names_file_to_dir(char *dir_name, char *file_name)
{
	char	*to_free;

	if (!dir_name)
		return (ft_strdup(file_name)); //maybe its fucked
	to_free = 0;
	dir_name = ft_strjoin(dir_name, "/");
	to_free = dir_name;
	dir_name = ft_strjoin(dir_name, file_name);
	if (to_free)
		free(to_free);
	return (dir_name);
}

int		get_full_paths(t_files files,  char *dir_name, t_add_file_info *f_i)
{
	size_t			i;

	i = 0;
	while (i < files.size)
	{
		f_i[i].full_path = append_names_file_to_dir(dir_name, files.arr[i].name);
		i++;
	}
	return (0);
}
