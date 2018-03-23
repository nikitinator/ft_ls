/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:10:52 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 21:02:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_full_path(char *dir_name, char *file_name)
{
	char	*to_free;	

	to_free = 0;
	if (dir_name[ft_strlen(dir_name) - 1] != '/')
	{
		dir_name = ft_strjoin(dir_name, "/");
		to_free = dir_name;
	}
	dir_name = ft_strjoin(dir_name, file_name);
	if (to_free)
		free(to_free);
	return (dir_name);
}

void	get_files_from_dir(t_file dir, t_files *files, t_byte show_hidden)
{
	t_list			*file_list;
	char			*full_file_name;
	DIR				*dir_p;
	struct dirent	*dp;
	struct stat		file_stat;
	
	
	file_list = 0;
	dir_p = opendir(dir.name);//permission denied
	while ((dp = readdir(dir_p)))
	{
		full_file_name = get_full_path(dir.name, dp->d_name);
		if (!lstat(full_file_name, &file_stat))
		{
			if (show_hidden || !is_hidden(dp->d_name))
			{
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){ft_strdup(dp->d_name), file_stat}, sizeof(t_file));
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, files);
	ft_lstdel(&file_list, del_list);
	closedir(dir_p);
}

void	get_files_dirs_from_dir(t_file dir, t_files *files, t_files *dirs,
		t_byte show_hidden)
{
	t_list			*file_list;
	t_list			*dir_list;
	char			*full_file_name;
	struct dirent	*dp;
	struct stat		file_stat;
	DIR				*dir_p;
	
	file_list = 0;
	dir_list = 0;
	dir_p = opendir(dir.name);//permission denied
	while ((dp = readdir(dir_p)))
	{
		full_file_name = get_full_path(dir.name, dp->d_name);
		if (!lstat(full_file_name, &file_stat))
		{
			if (show_hidden == 1 || !is_hidden(dp->d_name))
			{
				if (is_dir(file_stat.st_mode))
					ft_list_push_front
						(&dir_list, &(t_file){ft_strdup(full_file_name), file_stat}, sizeof(t_file));
				ft_list_push_front(&file_list, //oooohhhhhhhhhhhh should i check it
					&(t_file){ft_strdup(dp->d_name), file_stat}, sizeof(t_file));
			}
		}
		free(full_file_name);
	}
	file_list_to_arr(file_list, files);
	file_list_to_arr(dir_list, dirs);
	ft_lstdel(&file_list, del_list);
	ft_lstdel(&dir_list, del_list);
	(void)closedir(dir_p);
}
