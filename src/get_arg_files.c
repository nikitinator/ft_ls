/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snikitin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:34:07 by snikitin          #+#    #+#             */
/*   Updated: 2018/03/19 15:41:26 by snikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//TODO you can delete it
static int	open_current_dir(t_dirs *dirs) //TODO leaks
{
	dirs->size = 1;
	if (!(dirs->name = malloc(sizeof(char *))))
		return (-1);
	dirs->name[0] = ft_strdup(".");
	if (!(dirs->dir_p = malloc(sizeof(DIR *))))
		return (-1);
	if (!(dirs->dir_p[0] = opendir(dirs->name[0])))
	{
		char *error;		//TODO uberi eto nahui

		perror(error);
		ft_putendl_fd(error, 2);
		return (-1);
	}
	return (0);
}

void	file_list_to_arr(t_list *file_list, t_list *dir_list,
		t_dir **dirs, t_file **files)
{
	int		i;

	if (*file_list)	
	{
		i = 0;
		*files = malloc((ft_list_count(file_list) + 1) * sizeof(t_file));
		while (*file_list)
		{
			*(files[i]) = (t_file)file_list->content;
			i++;
			file_list = file_list->next;
		}
		*(files[i]) = NULL;
	}
	if (*dir_list)	
	{
		i = 0;
		*dirs = malloc((ft_list_count(dir_list) + 1) * sizeof(t_dir));
		while (*dir_list)
		{
			*(dir[i]) = (t_dir)dir_list->content;
			i++;
			dir_list = dir_list->next;
		}
		*(dir[i]) = NULL;
	}
}

int		open_files_to_list(char **argv, t_list **file_lst, t_list **dir_lst)
{
	struct stat	stat;
	DIR		*dir_p;

	*files_list = NULL;
	*dirs_list = NULL;
	while (**argv)
	{
		if((dir_p = opendir(*argv)))
			ft_list_push_front(dirs_list, &(t_dir)(*argv, dir_p), sizeof(t_dir));
		else if ((stat(*argv, &stat)))
			ft_list_push_front(files_lis, &(t_files)(*argv, stat), sizeof(t_file));
		else
		{
			ft_putendl(*argv);
			ft_putendl("NEMA FILE, dlava ukraini");//TODO razberis s errorami	
		}
		argv++;
	}	
	return (0);
}

static void del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

int		get_arg_files(int argc, char **argv, t_dir **dirs, t_file **files)
{
	int		i;

	t_list **file_list;
	t_list **dir_list;
	
	//ft_bzero(dirs, sizeof(t_dirs));
	//ft_bzero(files, sizeof(t_files));
	i = 1;
	while(i < argc && *(argv[i]) == '-')
		i++;
	if (i == argc)
		return (open_current_dir(dirs));//TODO zamenit;
	open_files_to_list(argv + i, files_list, dirs_list);
	files_list_to_arr(*file_list, *dir_list, files, dirs);	
	ft_lstdel(file_list, del);
	ft_lstdel(dir_list, del);
	return (0);
}
