/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:47:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 21:45:37 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//void	print_list_long(t_files files, char *dir_path)// change that mothafucking name
//{
//	int				i;
//	t_space_num		*n_space; 
//	char			**owners;
//	char			**groups;
//	
//	(void) dir_path;
//	if (files.size == 0)
//		return ;
//	if (!(n_space = (t_space_num *)malloc(sizeof(t_space_num) * files.size)))
//		return ;
//	if ((get_owners_groups(files, &owners, &groups)))
//		return ;
//	get_space_num(files, owners, groups, n_space);	
//	i = 0; 
//	print_total(files);
//	while(i < files.size)
//	{
//		print_one_line(files.arr[i], dir_path, owners[i], groups[i], n_space[i]);
//		free(owners[i]);
//		free(groups[i]);
//		i++;
//	}
//	free(owners);
//	free(groups);
//	free(n_space);
//}
//

void	print_one_line(t_file file, char *dir_path,
		char *owner, char *group, t_space_num n_space)
{
	print_file_type(file.f_stat.st_mode);
	print_file_modes(file.f_stat.st_mode);
	print_sticky_bit(dir_path, file.name);
	print_n_spaces(n_space.links + 1);
	ft_putnbr(file.f_stat.st_nlink);
	print_n_spaces(n_space.owner + 1);
	ft_putstr(owner);
	print_n_spaces(2);
	ft_putstr(group);
	print_n_spaces(n_space.group);
	print_n_spaces(n_space.size + 2);
	ft_putnbr(file.f_stat.st_size);
	ft_putchar(' ');
	print_mod_time(file.f_stat.st_mtime);
	ft_putchar(' ');
	ft_putendl(file.name);
}

void	handle_sym_links(t_files files)
{
	t_uint	i;

	i = 0;
	while(i < files.size)
	{
		if (is_sym_link(files.arr[i].f_stat.st_mode))
		i++;
	}
}

int		get_owners_groups(t_files files, char ***ownrs_output,
		char ***grp_output)
{
	struct passwd *u_p;
	struct group *g_p;
	char	**owners;
	char	**groups;
	int		i;

	if (!(owners = (char **)malloc(files.size * sizeof(char *))))
		return (-1);
	if (!(groups = (char **)malloc(files.size * sizeof(char *))))
		return (-1);
	//handle_sym_links(files);
	i = 0;
	while (i < files.size)
	{
		u_p = getpwuid(files.arr[i].f_stat.st_uid);
		g_p = getgrgid(files.arr[i].f_stat.st_gid);
		owners[i] = ft_strdup(u_p->pw_name);
		groups[i] = ft_strdup(g_p->gr_name);
		i++;
	}
	*ownrs_output = owners;
	*grp_output = groups;
	return (0);
}



void	get_file_inf(t_files files, char *dir_path, t_add_file_info **inf)
{
	if (!(*inf = (t_add_file_info *)malloc(sieof(t_add_filie_info) * files.size)))
		return ;
	if (!(n_space = (t_space_num *)malloc(sizeof(t_space_num) * files.size)))
		return ;
	if ((get_owners_groups(files, *inf)))
		return ;
	get_space_num(files, inf);	
	get_full_names(files, dir, inf);

}

void	print_list_long(t_files files, char *dir_path)// change that mothafucking name
{
	int				i;
	t_add_file_info *inf;	
	if (files.size == 0)
		return ;
	get_file_info(files, dir_path, &inf)
	i = 0; 
	print_total(files);
	while(i < files.size)
	{
		print_one_line(files.arr[i], dir_path, owners[i], groups[i], n_space[i]);
		free(owners[i]);
		free(groups[i]);
		i++;
	}
	free(owners);
	free(groups);
	free(n_space);
}
