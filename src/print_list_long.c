/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:47:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/27 19:17:16 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_n_spaces(int n)
{
	ft_putnchar(n, ' ');
}

void	print_major_minor(dev_t	st_rdev, t_byte major_spaces, t_byte minor_spaces)
{
	int		major;
	int		minor;

	major = st_rdev >> 24 & 0xff;
	minor = st_rdev & 0xffffff;
	ft_putchar(' ');
	ft_putchar(' ');
	print_n_spaces(major_spaces);
	ft_putnbr(major);
	ft_putchar(',');
	ft_putchar(' ');
	print_n_spaces(minor_spaces);
	ft_putnbr(minor);
}


void	print_one_line(t_file file, t_add_file_info i)
{
	print_type(file.f_stat.st_mode);
	print_modes(file.f_stat.st_mode);
	print_sticky_bit(i.full_path);
	print_n_spaces(i.n_space.links + 1);
	ft_putnbr(file.f_stat.st_nlink);
	ft_putchar(' ');
	ft_putstr(i.owner);
	print_n_spaces(i.n_space.owner);
	print_n_spaces(2);
	ft_putstr(i.group);
	print_n_spaces(i.n_space.group);
	if (is_char_dev(file.f_stat.st_mode) || is_char_dev(file.f_stat.st_mode))
		print_major_minor(file.f_stat.st_rdev, i.n_space.major, i.n_space.minor);
	else
	{
		print_n_spaces(i.n_space.size + 2);
		ft_putnbr(file.f_stat.st_size);
	}

	ft_putchar(' ');
	print_mod_time(file.f_stat.st_mtime);
	ft_putchar(' ');
	ft_putendl(file.name);
}

//dodelai sukka;
void	handle_sym_links(t_files files, t_add_file_info *f_i)
{
	t_uint	i;
	char	*to_free;	
	char	buf[MAX_FILENAME_LEN];

	i = 0;
	while(i < files.size)
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

int		get_owners_groups(t_files files, t_add_file_info *f_i)
{
	struct passwd *u_p;
	struct group *g_p;
	int		i;

	//handle_sym_links(files);
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

int		get_file_inf(t_files files, char *dir_path, t_add_file_info **f_i)
{
	if (!(*f_i = (t_add_file_info *)malloc(sizeof(t_add_file_info) * files.size)))
		return (1);
	if ((get_owners_groups(files, *f_i)))
		return (1);
	if (get_full_paths(files, dir_path, *f_i))
		return (1);
	get_space_num(files, *f_i);	
	return (0);
}

void	print_list_long(t_files files, char *dir_path)// change that mothafucking name
{
	int				i;
	t_add_file_info *inf;	

	if (files.size == 0)
		return ;
	if (get_file_inf(files, dir_path, &inf))
		return ;
	handle_sym_links(files, inf);
	i = 0; 
	print_total(files);
	while(i < files.size)
	{
		print_one_line(files.arr[i], inf[i]);
		free(inf[i].owner);
		free(inf[i].group);
		free(inf[i].full_path);
		i++;
	}
	free(inf);
}
