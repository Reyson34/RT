/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:15:35 by temehenn          #+#    #+#             */
/*   Updated: 2018/11/08 12:04:25 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;

	i = 0;
	new = 0;
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (0);
	while (*src)
	{
		new[i++] = *src;
		src++;
	}
	new[i] = '\0';
	return (new);
}
