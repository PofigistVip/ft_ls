#ifndef FT_LS_H
# define FT_LS_H
# include <pwd.h>
# include <sys/stat.h>
# include "libft.h"

# define FTLS_OPT_L_LONG_FORMAT 1
# define FTLS_OPT_R_RECURSIVE 2
# define FTLS_OPT_A_ALL_FILES 4
# define FTLS_OPT_D_DIRS_AS_FILES 8
# define FTLS_OPT_G_COLORS 16

# define FTLS_SORT_F_NO_SORT 0
# define FTLS_SORT_R_REVERSE_ORDER 1
# define FTLS_SORT_T_SORT_BY_TIME 2

# define FTLST_COL_DIR

# define FTLS_OK 0
# define FTLS_USAGE 1

# define FTLS_ID_NAME_SIZE 5

typedef unsigned char		uchar;
typedef unsigned int		uint;

typedef struct s_id_name	t_id_name;
typedef struct s_elem		t_elem;

typedef struct				s_ft_ls
{
	uchar		options;
	uchar		sort;

	t_id_name	*user_ids;
	t_id_name	*group_ids;

	t_elem		*root;
}							t_ft_ls;


//id = (uint)-1 если элемент не задан
struct	s_id_name
{
	uint				id[FTLS_ID_NAME_SIZE];
	char				*name[FTLS_ID_NAME_SIZE];
	struct s_id_name	*next;
};

struct	s_elem
{
	struct stat		info;
	struct s_elem	*elems[10];
	struct s_elem	*next;
	uint			count;
};

/*
** id_name
*/

//RET NULL если не найдено, иначе строку с названием
char						*id_name_find(t_id_name *ids, int id);
//RET -1 при ошибке.
int							id_name_add(t_id_name **ids, int id, char *name);
void						id_name_free(t_id_name *ids);


/*
** elem
*/

//RET NULL если элемент не был добавлен
t_elem						*elem_add(t_elem	*folder);
//RET NULL если не найден элемент
t_elem						*elem_get(t_elem *folder, uint index);
void						elem_free(t_elem *root);


/*
** get_options.c
*/

int							get_options(t_ft_ls *ls, int argc, char **argv);

#endif