/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:33:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/28 12:51:16 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		puterror_perm_denied(char *file_name)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putendl_fd(": Permission denied", 2);//consider changing it later
}

static void	print_dir_name(char *name, t_byte *first)
{

	if (!*first)
		ft_putchar('\n');
	else
		*first = 0;
	ft_putstr(name);
	ft_putendl(":");
}

void	list_dir_normal(t_file dir, t_params params)
{
	t_files	files;

	ft_bzero(&files, sizeof(t_files));
	if (!get_files_from_dir(dir, params.show_hidden, &files))
	{
		list_files(files, ft_strdup(dir.name), params);
		free_files(files);
	}
	else
		puterror_perm_denied(dir.name);
}

void	list_dir_recurs(t_file dir, t_params params)
{	
	t_files	files;
	t_files	dirs;

	ft_bzero(&files, sizeof(t_files));
	ft_bzero(&dirs, sizeof(t_files));
	if (!get_files_dirs_from_dir(dir, params.show_hidden, &files, &dirs))
	{
		list_files(files, ft_strdup(dir.name),  params);
		list_dirs(dirs, params);
		free_files(files);
		free_dirs(dirs);
	}
	else
		puterror_perm_denied(dir.name);
	//free(dir.name);
}

void	list_dir(t_file dir, t_params params) //ne otpravlyai ves params
{	
	if (params.recursive)
		list_dir_recurs(dir, params);
	else 
		list_dir_normal(dir, params);
}

void	list_dirs(t_files dirs, t_params params)
{
	int		i;

	if (dirs.size == 0)
		return ;
	sort_files(dirs, params.time_modif);
	if (params.reverse)
		reverse_files(dirs);
	i = 0;
	while (i < dirs.size)
	{
		print_dir_name(dirs.arr[i].name, &params.first);//stydno (\n)
		list_dir(dirs.arr[i], params);
		free(dirs.arr[i].name);
		i++;
	}
}
