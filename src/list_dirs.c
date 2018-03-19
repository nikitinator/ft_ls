#include "ft_ls.h"

	DIR	*dir_p;
	struct dirent *dp;

	(void)argc;
	if (argc == 2)
	{
		if (!(dir_p = opendir(argv[1])))
			return (ERROR);
		while ((dp = readdir(dir_p)))
			ft_putendl(dp->d_name);
		(void)closedir(dir_p);	
	}
	return (0);



void	list_dirs(t_dirs dirs, t_params params)
{
	if (dirs->size == 0)
		return ;
}
