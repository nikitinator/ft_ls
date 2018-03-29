/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:11:49 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/28 15:17:31 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	print_type(mode_t st_mode)
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

void	print_modes(mode_t st_mode)
{
	ft_putstr((st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((st_mode & S_IWOTH) ? "w" : "-");
	if (st_mode & S_ISVTX)
		ft_putstr((st_mode & S_IXOTH) ? "t" : "T");
	else
		ft_putstr((st_mode & S_IXOTH) ? "x" : "-");
}

void	print_has_attr(char *full_path)
{
	//if (listxattr(full_path, NULL, 1, XATTR_NOSECURITY))
	if (listxattr(full_path, NULL, 1, XATTR_NOFOLLOW))
	// XATTR_SHOWCOMPRESSION, XATTR_NOFOLLOW))
		ft_putchar('@');
	else
		ft_putchar(' ');
}
