/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_get_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcottet <fcottet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 18:46:26 by fcottet           #+#    #+#             */
/*   Updated: 2019/06/18 16:34:16 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			get_vec(double vec[4], char *line)
{
	int		i;
	char	**split;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		return (E_ERROR);
	if (!(split = ft_strsplit(&(line[i + 1]), ';')) || !is_valid_vector(split))
		return (E_ERROR);
	i = 0;
	vec[0] = ft_atoi(split[i]);
	vec[1] = ft_atoi(split[i + 1]);
	vec[2] = ft_atoi(split[i + 2]);
	vec[3] = 1.0;
	free_tab(split);
	return (E_SUCCESS);
}

int			get_color(double color[4], char *line)
{
	int		i;
	char	**split;

	i = 0;
	while (line[i] && line[i] != ':')
		i++;
	if (!line[i])
		return (E_ERROR);
	if (!(split = ft_strsplit(&(line[i + 1]), ';')) || !is_valid_vector(split))
		return (E_ERROR);
	i = 0;
	color[2] = ft_atoi(split[i]);
	color[1] = ft_atoi(split[i + 1]);
	color[0] = ft_atoi(split[i + 2]);
	color[0] = color[0] / 255;
	color[1] = color[1] / 255;
	color[2] = color[2] / 255;
	free_tab(split);
	return (E_SUCCESS);
}

double		get_value(char *str)
{
	int		i;
	double	result;
	double	decimal;
	int		j;

	i = 0;
	result = 0;
	while (str[i] != ':' && str[i])
		i++;
	j = i;
	if (str[i])
		result = ft_atoi(&(str[i + 1]));
	while (str[i] != '.' && str[i])
		i++;
	if (!str[i])
		return (result);
	decimal = ft_atoi(&(str[i + 1]));
	while (decimal >= 1)
		decimal /= 10;
	result = result + decimal;
	return (str[j + 1] == '-') ? -result : result;
}

double		get_max(double a, double b)
{
	return (a > b) ? a : b;
}
