/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:06:39 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:45:53 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ants_attack(t_lem **tlen, t_top **tops, t_ant ***ants)
{
	int		arr[S_LINKS];
	int		i;
	int		give_way;

	i = -1;
	give_way = 0;
	ft_bzero(arr, (S_LINKS * 4));
	while (++i < S_LINKS)
		arr[i] = WAY[i][101];
	init_ants(tlen, ants, arr);
	attack_order(tlen, tops, ants);
}

void			init_ants(t_lem **tlen, t_ant ***ants, int *arr)
{
	int		i;

	i = -1;
	if (!((*ants) = (t_ant **)malloc(sizeof(t_ant *) * ANTS)))
		exit(0);
	while (++i < ANTS)
		if (!((*ants)[i] = (t_ant *)malloc(sizeof(t_ant))))
			exit(0);
	i = -1;
	if (ANTS > 2)
		while (++i < ANTS)
			fill_ants(tlen, ants, i, arr);
	else
		while (++i < ANTS)
			one_ant(tlen, ants, i);
}

void			fill_ants(t_lem **tlen, t_ant ***ants, int i, int *arr)
{
	(*ants)[i]->num = i + 1;
	(*ants)[i]->i = 0;
	(*ants)[i]->way = give_way(tlen, arr);
	(*ants)[i]->marching = 0;
}

int				*give_way(t_lem **tlen, int *arr)
{
	int		i;
	int		len;
	int		res;

	i = -1;
	len = 1000;
	res = 0;
	while (++i < S_LINKS && arr[i] != 0)
	{
		if (arr[i] < len && arr[i] != 1)
		{
			res = i;
			len = arr[i];
		}
	}
	arr[res] += 1;
	return (WAY[res]);
}

void			one_ant(t_lem **tlen, t_ant ***ants, int i)
{
	(*ants)[i]->num = i + 1;
	(*ants)[i]->i = 0;
	(*ants)[i]->marching = 0;
	(*ants)[i]->way = (*tlen)->min_way;
}
