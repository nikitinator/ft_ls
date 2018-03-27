/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:09:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/27 18:32:56 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

short	get_digit_num(int n)
{
	int		i;

	i = 1;
	while(n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);	
}

//add_mallocoo here
void	get_space_num(t_files files, t_add_file_info *f_i)
{
	size_t	i;
	t_space_num max_width;	

	i = 0;
	ft_bzero(&max_width, sizeof(t_space_num));
	while (i < files.size)
	{
		f_i[i].n_space.owner = ft_strlen(f_i[i].owner);
		f_i[i].n_space.group = ft_strlen(f_i[i].group);
		f_i[i].n_space.size = get_digit_num(files.arr[i].f_stat.st_size); 
		f_i[i].n_space.links = get_digit_num(files.arr[i].f_stat.st_nlink); 
		f_i[i].n_space.major = get_digit_num(files.arr[i].f_stat.st_rdev >> 24 & 0xff);
		f_i[i].n_space.minor = get_digit_num(files.arr[i].f_stat.st_rdev & 0xffffff);

		if (f_i[i].n_space.owner > max_width.owner)
			max_width.owner = f_i[i].n_space.owner;
		if (f_i[i].n_space.group > max_width.group)
			max_width.group = f_i[i].n_space.group;
		if (f_i[i].n_space.size > max_width.size)
			max_width.size = f_i[i].n_space.size;
		if (f_i[i].n_space.links > max_width.links)
			max_width.links = f_i[i].n_space.links;
		if (f_i[i].n_space.major > max_width.major)
			max_width.major = f_i[i].n_space.major;
		if (f_i[i].n_space.minor > max_width.minor)
			max_width.minor = f_i[i].n_space.minor;

		i++;	
	}
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