/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 14:41:13 by fcottet           #+#    #+#             */
/*   Updated: 2019/06/20 12:15:14 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_usage(void)
{
	ft_putendl("usage: rt file_name");
	exit(0);
}

void	error_file(void)
{
	ft_putendl("Bad config file");
	exit(0);
}

int		is_valid_fread(FILE *fimg)
{
	int	ret;

	ret = ferror(fimg);
	clearerr(fimg);
	return (!ret) ? 1 : 0;
}
