/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:09:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/04/06 17:54:08 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	update_max_width(t_space_num *max, t_space_num current)
{
	if (current.owner > max->owner)
		max->owner = current.owner;
	if (current.group > max->group)
		max->group = current.group;
	if (current.size > max->size)
		max->size = current.size;
	if (current.links > max->links)
		max->links = current.links;
}

static void	get_width(t_space_num *max, t_files files, t_add_file_info *f_i)
{
	size_t		i;

	i = 0;
	while (i < files.size)
	{
		ft_bzero(&f_i[i].n_space, sizeof(t_space_num));
		f_i[i].n_space.owner = ft_strlen(f_i[i].owner);
		f_i[i].n_space.group = ft_strlen(f_i[i].group);
		f_i[i].n_space.size = get_digit_num((int)files.arr[i].f_stat.st_size);
		f_i[i].n_space.links = get_digit_num(files.arr[i].f_stat.st_nlink);
		f_i[i].n_space.major =
			get_digit_num(MAJOR(files.arr[i].f_stat.st_rdev));
		f_i[i].n_space.minor =
			get_digit_num(MINOR(files.arr[i].f_stat.st_rdev));
		update_max_width(max, f_i[i].n_space);
		if ((is_char_dev(files.arr[i].f_stat.st_mode) ||
					is_blck_dev(files.arr[i].f_stat.st_mode))
				&& ((max->major + max->minor) > max->size))
			max->size = max->major + max->minor + 1;
		i++;
	}
}

void		get_space_num(t_files files, t_add_file_info *f_i)
{
	size_t		i;
	t_space_num max_width;

	ft_bzero(&max_width, sizeof(t_space_num));
	max_width.major = 3;
	max_width.minor = 4;
	get_width(&max_width, files, f_i);
	i = 0;
	while (i < files.size)
	{
		f_i[i].n_space.owner = max_width.owner - f_i[i].n_space.owner;
		f_i[i].n_space.group = max_width.group - f_i[i].n_space.group;
		f_i[i].n_space.size = max_width.size - f_i[i].n_space.size;
		f_i[i].n_space.links = max_width.links - f_i[i].n_space.links;
		f_i[i].n_space.major = max_width.major - f_i[i].n_space.major;
		f_i[i].n_space.minor = max_width.minor - f_i[i].n_space.minor;
		i++;
	}
}
