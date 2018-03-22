/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:55:51 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/22 13:36:51 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h" 

//TODO MIND THE FILE TYPED ALLAROUND THE FILEs

void	print_list_long(t_files files)
{
	int		i;
	
	i = 0; 
	while(i < files.size)
	{
		ft_putendl(files.arr[i].name);
		i++;
	}
}

void	print_list(t_files files)
{
	int		i;
	
	i = 0; 
	while(i < files.size)
	{
		ft_putendl(files.arr[i].name);
		i++;
	}
}

void	reverse_files(t_files files)
{
	(void)files;
	ft_putendl("reversed output :)");
}

void	sort_files_time_modif(t_files files)
{
	(void)files;
	ft_putendl("reversed output :)");
}

void	list_files(t_files files, t_params params)
{
	int		i;

	if (files.size == 0)
		return ;
	i = 0;
	sort_files(files, params.time_modif);
	if (params.reverse)
		reverse_files(files);
	if (params.long_format)
		print_list_long(files);
	else 
		print_list(files);
}
