/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:11:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 20:17:19 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_n_spaces(int n)
{
	while (n)
	{
		ft_putchar(' ');
		n--;
	}
}

void	print_total(t_files files)
{
	int			i;
	blkcnt_t	total_blocks_num;

	i = 0;
	total_blocks_num = 0;
	while (i < files.size)
	{
		total_blocks_num += files.arr[i].f_stat.st_blocks;
		i++;
	}
	ft_putstr("total");
	ft_putchar(' ');
	ft_putnbr(total_blocks_num);
	ft_putchar('\n');
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

void	print_sticky_bit(char *dir_path, char *file_name)
{
	char	*full_file_name;

	full_file_name = file_name;
	if (dir_path)
		full_file_name = get_full_path(dir_path, file_name);
	if (listxattr(full_file_name, NULL, 0, XATTR_NOFOLLOW))//XATTR_SHOWCOMPRESSION
		ft_putchar('@');
	else
		ft_putchar(' ');
	if (dir_path)
		free(full_file_name);
}
