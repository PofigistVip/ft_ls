#include "ft_ls.h"

inline static int	print_usage(void)
{
	ft_putstr("usage: ./ft_ls ***\n");
	return (FTLS_USAGE);
}

inline static int	process_option(t_ft_ls *ls, char flag)
{
	if (flag == 'h')
		return (print_usage());
	if (flag == 'l')
		ls->options |= FTLS_OPT_L_LONG_FORMAT;
	else if (flag == 'R')
		ls->options |= FTLS_OPT_R_RECURSIVE;
	else if (flag == 'a')
		ls->options |= FTLS_OPT_A_ALL_FILES;
	else if (flag == 'd')
		ls->options |= FTLS_OPT_D_DIRS_AS_FILES;
	else if (flag == 'G')
		ls->options |= FTLS_OPT_G_COLORS;
	else if (flag == 'f')
		ls->sort = FTLS_SORT_F_NO_SORT;
	else if (flag == 'r')
		ls->sort |= FTLS_SORT_R_REVERSE_ORDER;
	else if (flag == 't')
		ls->sort |= FTLS_SORT_T_SORT_BY_TIME;
	else
		return (print_usage());
	return (FTLS_OK);
}

int					get_options(t_ft_ls *ls, int argc, char **argv)
{
	int		i;
	int		j;
	char	flag;
	int		status;

	i = -1;
	while (++i < argc)
	{
		if (*(argv[i]) == '-')
		{
			j = 0;
			while (flag = argv[i][++j])
			{
				status = process_option(ls, flag);
				if (status != FTLS_OK)
					return (status);
			}
		}
	}
	return (status);
}
