/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:57:13 by olga              #+#    #+#             */
/*   Updated: 2019/10/31 03:37:32 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_fix_start_end(char *line, int *c, t_lem **tlen, char **buf)
{
	ft_split_validation(line, c);
	if (*c == 3)
		ft_start(line, *tlen);
	else
		ft_end(line, *tlen);
	*c = 1;
	ft_write_buf(buf, line);
}

void		ft_start_end_links(t_lem **tlen, t_top **tops)
{
	if (tops[S_NUM]->links == 0 || tops[E_NUM]->links == 0)
		error();
}

void		ft_start_end_nums(t_lem *tlen, t_top ***tops)
{
	int		c;

	c = -1;
	if (tlen->start_name == NULL || tlen->end_name == NULL \
	|| tlen->rooms == 0)
		error();
	while (++c < tlen->rooms)
	{
		if (!(ft_strcmp(tlen->start_name, (*tops)[c]->name)))
			tlen->start_num = c;
		else if (!(ft_strcmp(tlen->end_name, (*tops)[c]->name)))
			tlen->end_num = c;
	}
}

void		ft_start(char *line, t_lem *tlen)
{
	char		**ar;

	ar = ft_strsplit(line, ' ');
	if (tlen->start_name != NULL)
		error();
	tlen->start_name = ft_strdup(ar[0]);
	tlen->start_x = ft_atoi(ar[1]);
	tlen->start_y = ft_atoi(ar[2]);
	ft_split_free(ar);
}

void		ft_end(char *line, t_lem *tlen)
{
	char		**ar;

	ar = ft_strsplit(line, ' ');
	if (tlen->end_name != NULL)
		error();
	tlen->end_name = ft_strdup(ar[0]);
	tlen->end_x = ft_atoi(ar[1]);
	tlen->end_y = ft_atoi(ar[2]);
	ft_split_free(ar);
}
