/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mesh_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:28:09 by lterrail          #+#    #+#             */
/*   Updated: 2019/06/18 17:43:33 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_float(char *str)
{
	int		i;
	double	result;
	double	decimal;
	int		zero;

	i = 0;
	zero = 0;
	result = 0;
	if (str[i] == '-')
		i++;
	result = ft_atoi(&(str[i]));
	while (str[i] != '.' && str[i])
		if (str[i++] == ' ')
			return (result);
	if (!str[i])
		return (result);
	decimal = ft_atoi(&(str[i + 1]));
	while (str[i + 1 + zero] && str[i + 1 + zero] == '0')
		zero++;
	while (decimal >= 1)
		decimal /= 10;
	while (--zero >= 0)
		decimal /= 10;
	result = result + decimal;
	return (str[0] == '-') ? -result : result;
}

static int		next_value(char *line, int j)
{
	int		i;

	i = 0;
	while (j > 0)
	{
		while (line[i] && line[i] != ' ' && line[i] != '\t')
			i++;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		j--;
	}
	return (i);
}

static int		next_face(char *line, int j)
{
	int		i;
	int		slash;

	i = 2;
	slash = 0;
	while (j > 0)
	{
		while (line[i] && slash != 2)
		{
			if (line[i] == '/')
				slash++;
			i++;
		}
		slash = 0;
		j--;
	}
	return (i);
}

int				fill_mesh_value(double v[4], double vn[4],
		char tab[MAX_LINE][MAX_COLUMN], int *pos)
{
	int		line;
	int		i;

	i = -1;
	while (++i < 3)
	{
		line = ft_atoi(&tab[pos[2]][next_value(tab[pos[2]], pos[3])])
			+ pos[0] - 1;
		if (line < 0 || line > pos[1])
			return (E_ERROR);
		v[i] = get_float(&tab[line][next_value(tab[line], i + 1)]);
		line = ft_atoi(&tab[pos[2]][next_face(tab[pos[2]], pos[3])])
			+ pos[1] - 1;
		if (line < 0 || line > pos[2])
			return (E_ERROR);
		vn[i] = get_float(&tab[line][next_value(tab[line], i + 1)]);
	}
	v[3] = 1;
	vn[3] = 1;
	return (E_SUCCESS);
}
