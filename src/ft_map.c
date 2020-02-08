/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 01:54:13 by olga              #+#    #+#             */
/*   Updated: 2019/10/31 03:29:15 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_map_links_2(t_lem *tlen, t_top ***tops, int i1, int i2)
{
	tlen->map[i1][i2] = 1;
	tlen->map[i2][i1] = 1;
	(*tops)[i1]->links++;
	(*tops)[i2]->links++;
}

void		ft_map_links(char **link, t_lem *tlen, t_top ***tops)
{
	int		i1;
	int		i2;
	int		num;

	i1 = -1;
	i2 = -1;
	num = -1;
	while (++num < tlen->rooms)
	{
		if (!(strcmp(link[0], (*tops)[num]->name)))
		{
			i1 = num;
			if (i1 != -1 && i2 != -1)
				break ;
		}
		else if (!(strcmp(link[1], (*tops)[num]->name)))
		{
			i2 = num;
			if (i1 != -1 && i2 != -1)
				break ;
		}
	}
	if (i1 == -1 || i2 == -1)
		error();
	ft_map_links_2(tlen, tops, i1, i2);
}

void		ft_map_null(t_lem **tlen, int i, int c)
{
	int		j;

	j = -1;
	while (++j < i)
		MAP[c][j] = 0;
}

void		ft_create_map(t_lem **tlen, int i)
{
	int		c;

	c = -1;
	if (i < 2)
		error();
	if (!((*tlen)->map = (int **)malloc(sizeof(int *) * i)))
		exit(0);
	while (++c < i)
	{
		if (!((*tlen)->map[c] = (int *)malloc(sizeof(int) * i)))
			exit(0);
		ft_map_null(tlen, i, c);
	}
}
