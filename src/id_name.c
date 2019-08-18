#include "ft_ls.h"

//RET NULL если не найдено, иначе строку с названием
char						*id_name_find(t_id_name *ids, int id)
{
	int		i;

	if (!ids)
		return (NULL);
	while (ids)
	{
		i = -1;
		while (++i < FTLS_ID_NAME_SIZE)
			if (ids->id[i] == id)
				return (ids->name + i);
			else if (ids->id[i] == (uint)-1)
				return (NULL);
		ids = ids->next;
	}
	return (NULL);
}

static t_id_name			*id_name_new(void)
{
	t_id_name	*id_name;

	if ((id_name = (t_id_name*)ft_memalloc(sizeof(t_id_name))) == NULL)
		return (NULL);
	//убедится что заполнится (uint_max)
	ft_memset(id_name->id, -1, FTLS_ID_NAME_SIZE);
	return (id_name);
}

static void					id_name_set(t_id_name *id_name, uint id, char *name)
{
	int		i;

	i = -1;
	while (++i < FTLS_ID_NAME_SIZE)
		if (id_name->id[i] == (uint)-1)
		{
			id_name->id[i] = id;
			id_name->name[i] = name;
			return ;
		}
}

//RET -1 при ошибке.
//Разобраться Необходимо ли копировать name?
int							id_name_add(t_id_name **ids, uint id, char *name)
{
	t_id_name	*curr_id;
	t_id_name	*prev_id;

	prev_id = NULL;
	curr_id = *ids;
	while (curr_id)
	{
		prev_id = curr_id;
		if (curr_id->id[FTLS_ID_NAME_SIZE - 1] != (uint)-1)
			curr_id = curr_id->next;
		else
		{
			id_name_set(curr_id, id, name);
			return (FTLS_OK);
		}
	}
	//Все текущие блоки заполнены полностью
	if ((curr_id = id_name_new()) == NULL)
		return (-1);
	curr_id->id[0] = id;
	curr_id->name[0] = name;
	if (prev_id == NULL)
		*ids = curr_id;
	else
		prev_id->next = curr_id;
	return (FTLS_OK);
}

void						id_name_free(t_id_name *ids)
{
	t_id_name	*next_ids;

	while (ids)
	{
		next_ids = ids->next;
		//foreach name -> free(name);
		free(ids);
		ids = next_ids;
	}
}
