/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:53:21 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/30 17:11:49 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_one_line(t_file file, t_add_file_info i)
{
	print_type(file.f_stat.st_mode);
	print_modes(file.f_stat.st_mode);
	print_has_ext_attr(i.full_path);
	ft_putchar(' ');
	putnbr_align((int)file.f_stat.st_nlink, i.n_space.links);
	ft_putchar(' ');
	putstr_align(i.owner, i.n_space.owner);
	print_n_spaces(2);
	putstr_align(i.group, i.n_space.group);
	print_n_spaces(2);
	if (is_char_dev(file.f_stat.st_mode) || is_blck_dev(file.f_stat.st_mode))
		print_major_minor(file.f_stat.st_rdev,
				i.n_space.major, i.n_space.minor);
	else
		putnbr_align(file.f_stat.st_size, i.n_space.size);
	ft_putchar(' ');
	print_mod_time(file.f_stat.st_mtime);
	ft_putchar(' ');
	ft_putendl(file.name);
}

void			handle_sym_links(t_files files, t_add_file_info *f_i)
{
	t_uint	i;
	char	*to_free;
	char	buf[MAX_FILENAME_LEN];

	i = 0;
	while (i < files.size)
	{
		if (is_sym_link(files.arr[i].f_stat.st_mode))
		{
			ft_bzero(buf, MAX_FILENAME_LEN);
			to_free = files.arr[i].name;
			files.arr[i].name = ft_strjoin(files.arr[i].name, " -> ");
			free(to_free);
			readlink(f_i[i].full_path, buf, MAX_FILENAME_LEN);
			to_free = files.arr[i].name;
			files.arr[i].name = ft_strjoin(files.arr[i].name, buf);
			free(to_free);
		}
		i++;
	}
}

int				get_owners_groups(t_files files, t_add_file_info *f_i)
{
	struct passwd	*u_p;
	struct group	*g_p;
	int				i;

	i = 0;
	while (i < files.size)
	{
		u_p = getpwuid(files.arr[i].f_stat.st_uid);
		g_p = getgrgid(files.arr[i].f_stat.st_gid);
		f_i[i].owner = ft_strdup(u_p->pw_name);
		f_i[i].group = ft_strdup(g_p->gr_name);
		i++;
	}
	return (0);
}

static int		get_file_info(t_files files, char *dir_path,
		t_add_file_info **f_i)
{
	if (!(*f_i = (t_add_file_info *)
				malloc(sizeof(t_add_file_info) * files.size)))
		return (1);
	if ((get_owners_groups(files, *f_i)))
		return (1);
	if (get_full_paths(files, dir_path, *f_i))
		return (1);
	get_space_num(files, *f_i);
	return (0);
}

void			print_files_long(t_files files, char *dir_path)
{
	int				i;
	t_add_file_info *inf;

	if (files.size == 0)
		return ;
	if (get_file_info(files, dir_path, &inf))
		return ;
	handle_sym_links(files, inf);
	i = 0;
	while (i < files.size)
	{
		print_one_line(files.arr[i], inf[i]);
		free(files.arr[i].name);
		free(inf[i].owner);
		free(inf[i].group);
		free(inf[i].full_path);
		i++;
	}
	free(inf);
}
