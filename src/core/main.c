/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:41:52 by temehenn          #+#    #+#             */
/*   Updated: 2019/06/18 19:47:39 by lterrail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	t_all		all;

	if (ac != 2 && av[1])
		ft_usage();
	all.av = av[1];
	all = init_var(all);
	core(&all);
	mlx_key_hook(all.mlx.p_win, event, &all);
	mlx_loop(all.mlx.p_mlx);
	return (E_SUCCESS);
}
