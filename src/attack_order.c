/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:04:25 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:46:54 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		attack_order(t_lem **tlen, t_top **tops, t_ant ***ants)
{
	int		i;
	int		j;
	int		ways[S_LINKS];

	i = -1;
	j = 0;
	ft_bzero(ways, (S_LINKS * 4));
	while (++i < ANTS)
		if (check_ways_num(tlen, ants, ways, i) == OK)
			ways[j++] = (*ants)[i]->way[0];
	i = -1;
	while ((*tlen)->ant_count < ANTS)
		lets_go(tlen, tops, ants);
}

int			check_ways_num(t_lem **tlen, t_ant ***ants, int *ways, int i)
{
	int		j;

	j = -1;
	while (++j < S_LINKS || ways[j] != 0)
		if ((*ants)[i]->way[0] == ways[j])
			return (ERROR);
	return (OK);
}

void		lets_go(t_lem **tlen, t_top **tops, t_ant ***ants)
{
	int		i;

	i = -1;
	(*tlen)->lines++;
	while (++i < ANTS)
	{
		if ((*ants)[i]->marching == 0)
			start_march(tops, ants, i, tlen);
		else if ((*ants)[i]->marching == 1)
			keep_way(tlen, tops, ants, i);
		if (i == ANTS - 1 && tops[E_NUM]->booking == -1)
			tops[E_NUM]->booking = 0;
	}
	write(1, "\n", 1);
}

void		start_march(t_top **tops, t_ant ***ants, int i, t_lem **tlen)
{
	if (tops[(*ants)[i]->way[(*ants)[i]->i + 1]]->booking == -1)
		return ;
	if (tops[(*ants)[i]->way[(*ants)[i]->i + 1]]->booking == 0)
	{
		(*ants)[i]->marching = 1;
		(*ants)[i]->i++;
		if ((*ants)[i]->way[(*ants)[i]->i] == E_NUM)
		{
			tops[(*ants)[i]->way[(*ants)[i]->i]]->booking = -1;
			(*ants)[i]->marching = 2;
			(*tlen)->ant_count += 1;
		}
		else
			tops[(*ants)[i]->way[(*ants)[i]->i]]->booking = 1;
		write(1, "L", 1);
		ft_putnbr((*ants)[i]->num);
		write(1, "-", 1);
		write(1, tops[(*ants)[i]->way[(*ants)[i]->i]]->name,
			ft_strlen(tops[(*ants)[i]->way[(*ants)[i]->i]]->name));
		write(1, " ", 1);
	}
}

void		keep_way(t_lem **tlen, t_top **tops, t_ant ***ants, int i)
{
	tops[(*ants)[i]->way[(*ants)[i]->i]]->booking = 0;
	(*ants)[i]->i++;
	if ((*ants)[i]->way[((*ants)[i]->i)] == E_NUM)
	{
		(*ants)[i]->marching = 2;
		(*tlen)->ant_count += 1;
	}
	write(1, "L", 1);
	ft_putnbr((*ants)[i]->num);
	write(1, "-", 1);
	write(1, tops[(*ants)[i]->way[(*ants)[i]->i]]->name,
		ft_strlen(tops[(*ants)[i]->way[(*ants)[i]->i]]->name));
	write(1, " ", 1);
}
