/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mesh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:01:32 by lterrail          #+#    #+#             */
/*   Updated: 2019/06/18 19:48:03 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		fill_position(char tab[MAX_LINE][MAX_COLUMN], int *v_start,
		int *vn_start, int *f_start)
{
	int		i;

	i = 0;
	*v_start = 0;
	*vn_start = 0;
	*f_start = 0;
	while (i < MAX_LINE - 1 && ft_strncmp(tab[i], "v ", 2))
		i++;
	*v_start = i;
	while (i < MAX_LINE - 1 && !ft_strncmp(tab[i], "v ", 2))
		i++;
	while (i < MAX_LINE - 1 && ft_strncmp(tab[i], "vn ", 3))
		i++;
	*vn_start = i;
	while (i < MAX_LINE - 1 && !ft_strncmp(tab[i], "vn ", 3))
		i++;
	while (i < MAX_LINE - 1 && ft_strncmp(tab[i], "f ", 2))
		i++;
	*f_start = i;
	if (i == MAX_LINE - 1)
		return (E_ERROR);
	return (E_SUCCESS);
}

static int		create_mesh_list(t_obj *obj, char tab[MAX_LINE][MAX_COLUMN],
			int *pos, int *id)
{
	t_obj	*new;

	if (!(new = malloc(sizeof(t_obj))))
		return (0);
	ft_memcpy(new, obj, sizeof(t_obj));
	new->next = NULL;
	new->id = *id;
	pos[3] = 1;
	if (!(fill_mesh_value(new->mesh.v0, new->mesh.vn0, tab, pos)))
		return (E_ERROR);
	pos[3]++;
	if (!(fill_mesh_value(new->mesh.v1, new->mesh.vn1, tab, pos)))
		return (E_ERROR);
	pos[3]++;
	if (!(fill_mesh_value(new->mesh.v2, new->mesh.vn2, tab, pos)))
		return (E_ERROR);
	if (obj->down == NULL)
		obj->down = new;
	else
		add_obj(&(obj->down), new);
	return (E_SUCCESS);
}

static int		init_mesh(t_obj *obj, char tab[MAX_LINE][MAX_COLUMN],
			int tot_line, int *id)
{
	int		pos[4];

	obj->down = NULL;
	if (obj->path)
	{
		free(obj->path);
		obj->path = NULL;
	}
	init_transform(&obj->t, obj->pos, obj->dir);
	if (!fill_position(tab, &pos[0], &pos[1], &pos[2]))
		return (E_ERROR);
	while (pos[2] <= tot_line)
	{
		if (!(create_mesh_list(obj, tab, pos, id)))
			return (E_ERROR);
		(*id)++;
		pos[2]++;
	}
	return (E_SUCCESS);
}

int				check_mesh(t_obj *obj, int *id)
{
	int		fd;
	int		i;
	char	*line;
	char	tab[MAX_LINE][MAX_COLUMN];

	i = -1;
	ft_bzero(tab, MAX_LINE * MAX_COLUMN);
	if ((fd = open(obj->path, O_RDONLY)) == -1
		|| ft_strcmp(".obj", obj->path + ft_strlen(obj->path) - 4) != 0)
		return (OPEN_OBJ_FILE_FAILED);
	while (get_next_line(fd, &line) > 0 && ++i < MAX_LINE - 1)
	{
		if (ft_strlen(line) >= MAX_COLUMN)
			return (OBJ_FILE_TOO_BIG);
		ft_memcpy(tab[i], line, ft_strlen(line));
		free(line);
	}
	if (i == MAX_LINE - 1 || !init_mesh(obj, tab, i, id))
		return (ERR_MESH);
	close(fd);
	return (E_SUCCESS);
}
