/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:44:59 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 14:18:57 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	print_file_type(mode_t st_mode)
{
	mode_t	file_type;

	file_type = st_mode & S_IFMT;
	if (file_type == S_IFBLK)
		ft_putstr("block device\n");        
	else if (file_type == S_IFCHR)
		ft_putstr("character device\n");    
    else if (file_type == S_IFDIR)
		ft_putstr("directory\n");           
    else if (file_type == S_IFIFO)
		ft_putstr("FIFO/pipe\n");           
    else if (file_type == S_IFLNK)
		ft_putstr("symlink\n");             
    else if (file_type == S_IFREG)
		ft_putstr("regular file\n");        
    else if (file_type == S_IFSOCK)
		ft_putstr("socket\n");              
	else
		ft_putstr("ERRRORORORO\n");              
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

int		main(int argc, char **argv)
{
	struct stat s_p;
	struct passwd *u_p;
	struct group *g_p;

	if (argc == 2)
	{	
		stat(argv[1], &s_p);

		ft_putstr("NAME: ");
		ft_putendl(argv[1]);

		ft_putstr("TYPE: ");
		print_file_type(s_p.st_mode);
		
		ft_putstr("MODES: ");
		print_file_modes(s_p.st_mode);
		ft_putchar('\n');

		ft_putstr("NUM_OF_LINKS: ");
		ft_putnbr((long)s_p.st_nlink);
		ft_putchar('\n');

		ft_putstr("GROUP: ");
		g_p = getgrgid(s_p.st_gid);
		ft_putendl(g_p->gr_name);

		ft_putstr("OWNER: ");
		u_p = getpwuid(s_p.st_uid);
		ft_putendl(u_p->pw_name);

		ft_putstr("SIZE: ");
		ft_putnbr(s_p.st_size);
		ft_putchar('\n');

		ft_putstr("LAST_MOD_DATE: ");
		ft_putendl(ctime(&s_p.st_mtime));
	}
	return (0);
}	

int		main(int argc, char **argv)
{
	DIR	*dir_p;
	struct dirent *dp;

	(void)argc;
	if (argc == 2)
	{
		if (!(dir_p = opendir(argv[1])))
		{
			ft_putendl("what");
			return (ERROR);
		}
		while ((dp = readdir(dir_p)))
			ft_putendl(dp->d_name);
		(void)closedir(dir_p);	
	}
	return (0);
}
