/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:47:02 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 21:36:24 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_n_spaces(int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

short	get_digit_num(int n)
{
	int		i;

	i = 1;
	while(n)
	{
		n /= 10;
		i++;
	}
	return (i);	
}

void	print_total(t_files files)
{
	(void)files;
	ft_putendl("total");
}

void	print_file_type(mode_t st_mode)
{
	mode_t	file_type;

	file_type = st_mode & S_IFMT;
    if (file_type == S_IFREG)
		ft_putstr("-");        
    else if (file_type == S_IFDIR)
		ft_putstr("d");           
    else if (file_type == S_IFLNK)
		ft_putstr("l");             
    else if (file_type == S_IFSOCK)
		ft_putstr("s");              
	else if (file_type == S_IFBLK)
		ft_putstr("b");        
	else if (file_type == S_IFCHR)
		ft_putstr("c");    
    else if (file_type == S_IFIFO)
		ft_putstr("p");           
	else
		ft_putstr("-");              
}

void	print_file_modes(mode_t st_mode)
{
    ft_putstr((st_mode & S_IRUSR) ? "r" : "-");
    ft_putstr((st_mode & S_IWUSR) ? "w" : "-");
    ft_putstr((st_mode & S_IXUSR) ? "x" : "-");
    ft_putstr((st_mode & S_IRGRP) ? "r" : "-");
    ft_putstr((st_mode & S_IWGRP) ? "w" : "-");
    ft_putstr((st_mode & S_IXGRP) ? "x" : "-");
    ft_putstr((st_mode & S_IROTH) ? "r" : "-");
    ft_putstr((st_mode & S_IWOTH) ? "w" : "-");
    ft_putstr((st_mode & S_IXOTH) ? "x" : "-");
}

void	print_one_line(t_file file, char *owner, char *group, t_space_num n_space)
{
	print_file_type(file.f_stat.st_mode);
	print_file_modes(file.f_stat.st_mode);

	ft_putchar(' ');
	print_n_spaces(n_space.links);
	ft_putnbr(file.f_stat.st_nlink);

	ft_putchar(' ');
	ft_putchar(' ');
	print_n_spaces(n_space.owner);
	ft_putstr(owner);
	
	ft_putchar(' ');
	ft_putstr(group);
	print_n_spaces(n_space.group);

	ft_putchar(' ');
	ft_putchar(' ');
	print_n_spaces(n_space.size);
	ft_putnbr(file.f_stat.st_size);

	//ft_putchar(' ');
	//ft_putstr(ctime(&file.f_stat.st_mtime));

	ft_putchar(' ');
	ft_putendl(file.name);
}

void	get_space_num(t_files files, char **owners, char **groups, t_space_num *n_space)
{
	t_byte	i;
	t_space_num max_width;	

	i = 0;
	ft_bzero(&max_width, sizeof(t_space_num));
	while (i < files.size)
	{
		n_space[i].owner = ft_strlen(owners[i]);
		n_space[i].group = ft_strlen(groups[i]);
		n_space[i].size = get_digit_num(files.arr[i].f_stat.st_size); 
		n_space[i].links = get_digit_num(files.arr[i].f_stat.st_nlink); 
		if (n_space[i].owner > max_width.owner)
			max_width.owner = n_space[i].owner;
		if (n_space[i].group > max_width.group)
			max_width.group = n_space[i].group;
		if (n_space[i].size > max_width.size)
			max_width.size = n_space[i].size;
		if (n_space[i].links > max_width.links)
			max_width.links = n_space[i].links;
		i++;	
	}
	i = 0;
	while (i < files.size)
	{
		n_space[i].owner = max_width.owner - n_space[i].owner;
		n_space[i].group = max_width.group - n_space[i].group;
		n_space[i].size = max_width.size - n_space[i].size;
		n_space[i].links = max_width.links - n_space[i].links;
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

void	print_list_long(t_files files)
{
	int				i;
	t_space_num		*n_space; 
	char			**owners;
	char			**groups;
	
	if (files.size == 0)
		return ;
	if (!(n_space = (t_space_num *)malloc(sizeof(t_space_num) * files.size)))
		return ;
	if ((get_owners_groups(files, &owners, &groups)))
		return ;
	get_space_num(files, owners, groups, n_space);	
	i = 0; 
	print_total(files);
	while(i < files.size)
	{
		print_one_line(files.arr[i], owners[i], groups[i], n_space[i]);
		free(owners[i]);
		free(groups[i]);
		i++;
	}
	free(owners);
	free(groups);
	free(n_space);
}
