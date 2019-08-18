#include "ft_ls.h"

inline static int	print_usage(void)
{
	ft_putstr("usage: ./ft_ls [-GRadfrt] path1 [path2 ...]\n");
	ft_pustr("Flags:\n");
	ft_putstr("\t-G - Enable colour output\n");
	ft_putstr("\t-R - Recursively list subdirectories encountered\n");
	ft_putstr("\t-a - List all entries including those starting with a dot\n");
	ft_putstr("\t-d - Directories are listed as plain files\n");
	ft_putstr("\t-f - Output is not sorted\n");
	ft_putstr("\t-r - Reverse the order of the sort\n");
	ft_putstr("\t-t - Sort by time modified (most recently modified first)\n");
	return (FTLS_USAGE);
}

inline static int	process_option(t_ft_ls *ls, char flag)
{
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
