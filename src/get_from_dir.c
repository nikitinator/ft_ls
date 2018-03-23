/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:10:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 18:56:25 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_hidden(char *name)
{
	return (*name == '.');
}

char	*append_names_file_to_dir(char *dir_name, char *file_name)
{
	char	*result;
	char	*to_free;	

	result = ft_strjoin(dir_name, "/");
	to_free = result;
	result = ft_strjoin(result, file_name);
	free(to_free);
	return (result);
}

void	get_files_from_dir(t_dir dir, t_files *files, t_params params) //limit params to one parameter
{
	t_list			*file_list;
	char			*full_file_name;
	struct dirent	*dp;
	struct stat		file_stat;
	
	file_list = 0;
	while ((dp = readdir(dir.dir_p)))
	{

		full_file_name = append_names_file_to_dir(dir.name, dp->d_name);
		if (!lstat(full_file_name, &file_stat))
		{
			if (params.show_hidden == 1 || !is_hidden(dp->d_name))
			{
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){ft_strdup(dp->d_name), file_stat}, sizeof(t_file));
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, files);
	ft_lstdel(&file_list, del_list);
}

void	get_files_dirs_from_dir(t_dir dir, t_files *files, t_dirs *dirs,
		 t_params params) //limit params to one parameter
{
	t_list			*file_list;
	t_list			*dir_list;
	char			*full_file_name;
	struct dirent	*dp;
	struct stat		file_stat;
	DIR				*dir_p;
	
	file_list = 0;
	dir_list = 0;
	while ((dp = readdir(dir.dir_p)))
	{

		full_file_name = append_names_file_to_dir(dir.name, dp->d_name);
		if (!lstat(full_file_name, &file_stat))
		{
			if (params.show_hidden == 1 || !is_hidden(dp->d_name))
			{
				if ((dir_p = opendir(full_file_name)))
					ft_list_push_front
						(&dir_list, &(t_dir){ft_strdup(full_file_name),
						 file_stat, dir_p}, sizeof(t_dir));
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){ft_strdup(dp->d_name), file_stat}, sizeof(t_file));
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, files);
	dir_list_to_arr(dir_list, dirs);
	ft_lstdel(&file_list, del_list);
	ft_lstdel(&dir_list, del_list);
}
