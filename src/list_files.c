/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:55:51 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/19 15:48:33 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h" 

int		is_hidden(char *str)
{
	return (*str == '.');
}

void	list_files(t_file *files, t_params params)
{
	if (files->size == 0)
		return ;
	while(*files)
	{
		//if (params->show_hidden)
		ft_putendl(files->name);
		files++;
	}

}
