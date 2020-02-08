/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:39:30 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:33:48 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_validation_links(char *line, t_lem *tlen, t_top ***tops)
{
	char	**ar;
	char	**link;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(line) - 1;
	j = -1;
	i = -1;
	if (*line == ' ' || line[len] == ' ' || *line == '-' \
	|| line[len] == '-' || !(ft_double(line, '-')))
		error();
	ar = ft_strsplit(line, ' ');
	while (ar[++j] != NULL)
		;
	link = ft_strsplit(ar[0], '-');
	while (link[++i] != NULL)
		;
	if (j != 1 || i != 2 || link[1][0] == ' ' \
	|| link[0][ft_strlen(link[0]) - 1] == ' ')
		error();
	ft_map_links(link, tlen, tops);
	ft_split_free(ar);
	ft_split_free(link);
}

void		ft_split_validation(char *line, int *c)
{
	char	**ar;
	int		i;

	i = -1;
	ar = ft_strsplit(line, ' ');
	while (ar[++i] != NULL)
		;
	if (i == 1 && *c == 1)
	{
		*c = 2;
		ft_split_free(ar);
		return ;
	}
	else if (i != 3 || ft_while_digit(ar[1]) || ft_while_digit(ar[2]) \
	|| (!(ft_atoi(ar[1])) && (ft_strcmp(ar[1], "0"))) \
	|| (!(ft_atoi(ar[2])) && (ft_strcmp(ar[2], "0"))) || ar[0][0] == 'L' \
	|| ft_while_isprint(ar[0]) || ar[0][0] == '-')
		error();
	ft_split_free(ar);
}

void		ft_validation_rooms(char *line, int *c)
{
	if (!(ft_strcmp(line, "##start")) || !(ft_strcmp(line, "##end")))
	{
		if (!(ft_strcmp(line, "##start")))
			*c = 3;
		else
			*c = 4;
		return ;
	}
	ft_split_validation(line, c);
}

void		ft_validation_ants(char *line, int *c, t_lem *tlen)
{
	if (ft_while_digit_plus(line) || !(ft_atoi(line)))
		error();
	(*c)++;
	tlen->ants = ft_atoi(line);
}

void		ft_validation(char *line, int *c, t_lem **tlen, t_top ***tops)
{
	static char	*buf;

	if (!buf)
		buf = NULL;
	if (*c == 3 || *c == 4)
	{
		ft_fix_start_end(line, c, tlen, &buf);
		return ;
	}
	if (line[0] == '#' && ft_strcmp(line, "##start") \
	&& ft_strcmp(line, "##end"))
		return ;
	if (*c == 0)
		ft_validation_ants(line, c, *tlen);
	else if (*c == 1)
	{
		ft_validation_rooms(line, c);
		if (*c == 1)
			ft_write_buf(&buf, line);
		else if (*c == 2)
			ft_write_tlen(tlen, buf, tops);
	}
	if (*c == 2)
		ft_validation_links(line, *tlen, tops);
}
