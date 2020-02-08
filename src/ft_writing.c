/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:32:42 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/29 03:16:17 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_valid_room(t_top ***tops, char **ar, int i)
{
	int		c;
	int		j;
	int		o;

	c = -1;
	j = ft_atoi(ar[1]);
	o = ft_atoi(ar[2]);
	while (++c < i)
		if (!(ft_strcmp(ar[0], (*tops)[c]->name)) || (j == (*tops)[c]->x \
		&& o == (*tops)[c]->y))
			error();
}

void		ft_write_tlen_params(char *s, t_top ***tops, int i)
{
	char	**ar;
	int		c;

	c = -1;
	ar = ft_strsplit(s, ' ');
	ft_valid_room(tops, ar, i);
	(*tops)[i]->name = ft_strdup(ar[0]);
	(*tops)[i]->x = ft_atoi(ar[1]);
	(*tops)[i]->y = ft_atoi(ar[2]);
	(*tops)[i]->links = 0;
	(*tops)[i]->turn = 0;
	(*tops)[i]->e_turn = 0;
	(*tops)[i]->stop = -1;
	(*tops)[i]->flag = -1;
	(*tops)[i]->booking = 0;
	(*tops)[i]->stack = 0;
	(*tops)[i]->alt_room = -1;
	(*tops)[i]->alt_way = -1;
	while (++c < 10)
		(*tops)[i]->book[c] = -1;
	ft_split_free(ar);
}

void		ft_top_tops(char **s, t_top ***tops, int i)
{
	int		c;

	c = -1;
	if (!((*tops) = (t_top **)malloc(sizeof(t_top *) * i)))
		exit(0);
	while (++c < i)
	{
		if (!((*tops)[c] = (t_top *)malloc(sizeof(t_top))))
			exit(0);
		ft_write_tlen_params(s[c], tops, c);
	}
}

void		ft_write_tlen(t_lem **tlen, char *buf, t_top ***tops)
{
	char	**ar;
	int		i;

	i = -1;
	if (buf == NULL)
		error();
	ar = ft_strsplit(buf, '\n');
	while (ar[++i] != NULL)
		;
	if (i == 0)
		error();
	ft_create_map(tlen, i);
	ft_top_tops(ar, tops, i);
	ROOMS = i;
	ft_split_free(ar);
}

void		ft_write_buf(char **buf, char *line)
{
	if (*line == ' ' || line[ft_strlen(line) - 1] == ' ')
		error();
	line = ft_strjoin(line, "\n");
	!(*buf) ? (*buf) = ft_strdup(line) : ft_first_free_join(buf, line);
	free(line);
}
