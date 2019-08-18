#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			status;
	t_ft_ls		*ls;

	status = 0;
	ls = ls_init(&status);
	if (status == 0)
		status = get_options(ls, argc - 1, argv + 1);
}