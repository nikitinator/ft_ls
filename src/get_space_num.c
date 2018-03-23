/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:09:03 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/23 15:10:58 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
