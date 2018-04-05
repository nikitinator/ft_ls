/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 17:33:44 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/05 18:51:53 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//void	print_dir_name(char *name)
//{
//	static char first_time = 1;
//
//	if (!first_time)
//		ft_putchar('\n');
//	else
//		first_time = 0;
//	ft_putstr(name);
//	ft_putendl(":");
//}

void	print_dir_name(char *name, t_byte *first_time)
{
	if (!*first_time)
		ft_putchar('\n');
	else
		*first_time = 0;
	ft_putstr(name);
	ft_putendl(":");
}

int		list_dir_normal(t_file dir, t_params params)
{
	t_files	files;

	ft_bzero(&files, sizeof(t_files));
	if (get_files_from_dir(dir, params.show_hidden, &files))
		return (1);
	if (params.long_format)
		print_total(files);
	list_files(files, dir.name, params);// ft_strdup dirs_name

	free_files(files);
	return (0);
}

int		list_dir_recurs(t_file dir, t_params params)
{	
	t_files	files;
	t_files	dirs;

	ft_bzero(&files, sizeof(t_files));
	ft_bzero(&dirs, sizeof(t_files));
	if (get_files_dirs_from_dir(dir, params.show_hidden, &files, &dirs))
		return (1);
	if (params.long_format)
		print_total(files);
	list_files(files, dir.name,  params);// ft_strdup dirs_name
	list_dirs(dirs, params);
	free_files(files);
	free_files(dirs);
	return (0);	
	//free(dir.name);
}

int		list_dir(t_file dir, t_params params) //ne otpravlyai ves params
{	
	if (params.recursive)
		return (list_dir_recurs(dir, params));
	else 
		return (list_dir_normal(dir, params));
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
		print_dir_name(dirs.arr[i].name, &params.first_time);
		if (list_dir(dirs.arr[i], params))
			puterror_perm_denied(dirs.arr[i].name);
		//free(dirs.arr[i].name);
		i++;
	}
}
