/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:47:11 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/31 03:43:40 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdarg.h>
# define BUFF_SIZE 8
# define OK 1
# define ERROR 0
# define S_NUM (*tlen)->start_num
# define E_NUM (*tlen)->end_num
# define M_WAY (*tlen)->min_way
# define ROOMS (*tlen)->rooms
# define MAP (*tlen)->map
# define MAP1 (*tlen)->map1
# define M_LVL (*tlen)->max_lvl
# define WAY (*tlen)->ways
# define KILL (*tlen)->kill
# define LEN (*tlen)->len
# define S_LINKS (*tlen)->s_links
# define ANTS (*tlen)->ants
# define VAR (*tlen)->variants
# define VAR_PR (*tlen)->var_pred
# define REP (*tlen)->repeat
# define IND (*tlen)->ways[c][101]

typedef struct		s_lem
{
	int				**ways;
	int				**variants;
	int				**var_pred;
	int				**repeat;
	int				**map;
	int				len;
	int				error;
	int				**map1;
	char			*start_name;
	char			*end_name;
	int				*min_way;
	int				ants;
	int				kill;
	int				rooms;
	int				ant_count;
	int				lines;
	int				s_links;
	int				run_run;
	int				max_lvl;
	long			start_x;
	long			start_y;
	int				start_num;
	long			end_x;
	long			end_y;
	int				end_num;
}					t_lem;

typedef struct		s_ant
{
	int				marching;
	int				*way;
	int				i;
	int				num;
}					t_ant;

typedef struct		s_top
{
	char			*name;
	int				x;
	int				y;
	int				flag;
	int				alt_way;
	int				alt_room;
	int				turn:16;
	int				e_turn:16;
	int				links;
	int				stop;
	int				stack;
	int				booking;
	int				book[10];
}					t_top;

int					get_next_line(const int fd, char **line);
/*
**main
*/
void				error();
void				ft_create_tlen(t_lem **tlen);
/*
**validation
*/
void				ft_validation_links(char *line, t_lem *tlen, t_top ***tops);
void				ft_validation_rooms(char *line, int *c);
void				ft_validation_ants(char *line, int *c, t_lem *tlen);
void				ft_validation(char *line, int *c, t_lem **tlen,
t_top ***tops);
void				ft_split_validation(char *line, int *c);
/*
**ft_writing
*/
void				ft_write_buf(char **buf, char *line);
void				ft_write_tlen(t_lem **tlen, char *buf, t_top ***tops);
void				ft_write_tlen_params(char *s, t_top ***tops, int i);
void				ft_top_tops(char **s, t_top ***tops, int i);
void				ft_valid_room(t_top ***tops, char **ar, int i);
/*
**ft_map
*/
void				ft_create_map(t_lem **tlen, int i);
void				ft_map_links_2(t_lem *tlen, t_top ***tops, int i1, int i2);
void				ft_map_null(t_lem **tlen, int i, int c);
void				ft_map_links(char **link, t_lem *tlen, t_top ***tops);
/*
**ft_start_end
*/
void				ft_start(char *line, t_lem *tlen);
void				ft_end(char *line, t_lem *tlen);
void				ft_start_end_nums(t_lem *tlen, t_top ***tops);
void				ft_start_end_links(t_lem **tlen, t_top **tops);
void				ft_fix_start_end(char *line, int *c,
t_lem **tlen, char **buf);
/*
**ft_map_change
*/
void				ft_copy_map(t_lem **tlen, int i);
void				ft_delete_tupak_2(t_lem **tlen, t_top **tops, int j);
void				ft_delete_tupak(t_lem **tlen, t_top **tops);
void				ft_create_map1(t_lem **tlen);
void				ft_map_change(t_lem *tlen, t_top **tops);
/*
**way_Day.c
*/
void				ft_kill_loops(t_lem **tlen, t_top **tops);
void				ft_rew_way(t_lem **tlen, t_top **tops);
void				ft_the_shortest_way2(t_lem **tlen, t_top **tops, int *j);
void				ft_the_shortest_way(t_lem **tlen, t_top **tops);
/*
**ft_rooms_level
*/
void				ft_level(t_lem **tlen, t_top **tops);
void				ft_create_stack(int *s, t_lem **tlen, int *c, int *i);
int					ft_level_one(t_lem **tlen, t_top **tops, int *s);
void				ft_tops_c(t_top **tops, int j, int c);
void				ft_tops_c1(t_top **tops, int *s, int i, int *c);
/*
**ft_the_shortest_way
*/
void				ft_the_best_way2(t_lem **tlen, t_top **tops, int *j, int c);
void				ft_null_number(t_lem **tlen, t_top **tops, int c);
void				ft_the_best_way(t_lem **tlen, t_top **tops, int c);
/*
**find_ways.c
*/
int					ft_i_like_it(t_lem **tlen, int d, int c, t_top **tops);
void				ft_another_tail(t_lem **tlen, t_top **tops, int *j, int c);
/*
**change_ways.c
*/
void				ft_three_good_bye(t_lem **tlen);
void				ft_close_way(t_lem **tlen, t_top **tops, int j, int c);
void				ft_close_node(t_lem **tlen, int j, int c);
void				ft_way_one(t_lem **tlen, int j, int c);
void				ft_rewers_way(t_lem **tlen, t_top **tops, int c);
/*
**end_level
*/
void				ft_end_level(t_lem **tlen, t_top **tops);
int					ft_level_end(t_lem **tlen, t_top **tops, int *s);
void				ft_create_stack_end(int **s, int i, int **tmp, int *c);
void				ft_stack_null(t_lem **tlen, t_top **tops);
/*
**shortest_ways
*/
void				ft_create_ways(t_lem **tlen);
void				ft_stack_for_ways(t_lem **tlen, t_top **tops, int c);
void				ft_find_ways(t_lem **tlen, t_top **tops, int c);
void				ft_shortest_ways(t_lem **tlen, t_top **tops);
/*
**ants_attack
*/
void				ants_attack(t_lem **tlen, t_top **tops, t_ant ***ants);
void				init_ants(t_lem **tlen, t_ant ***ants, int *arr);
void				fill_ants(t_lem **tlen, t_ant ***ants, int i, int *arr);
int					*give_way(t_lem **tlen, int *arr);
void				one_ant(t_lem **tlen, t_ant ***ants, int i);
/*
**attack_order.c
*/
void				attack_order(t_lem **tlen, t_top **tops, t_ant ***ants);
int					check_ways_num(t_lem **tlen, t_ant ***ants,
int *ways, int i);
void				lets_go(t_lem **tlen, t_top **tops, t_ant ***ants);
void				start_march(t_top **tops, t_ant ***ants, int i,
t_lem **tlen);
void				keep_way(t_lem **tlen, t_top **tops, t_ant ***ants, int i);
/*
**bonuses.c
*/
void				bonuses(t_lem **tlen, t_top **tops, char *av);
void				write_lines(t_lem **tlen);
void				write_ways(t_lem **tlen, t_top **tops);
void				write_with_steps(t_lem **tlen, t_top **tops);
/*
**colors.c
*/
void				red(void);
void				green(void);
void				reset(void);
void				cyan(void);
/*
**tools.c
*/
void				write_room(t_lem **tlen, t_top **tops, int i, int j);
void				write_steps(t_lem **tlen, int c);
/*
**test_ways
*/
void				ft_num_ways(t_lem **tlen);
int					ft_test_ways(t_lem **tlen, int c);
void				ft_clear_way(t_lem **tlen, t_top **tops, int c);
/*
**suurballe
*/
void				ft_suurballe_2(t_lem **tlen, t_top **tops, int c, int *j);
void				ft_suurballe(t_lem **tlen, t_top **tops, int c);
/*
**repeat_please
*/
void				ft_find_repeat(t_lem **tlen, t_top **tops);
void				ft_create_variants(t_lem **tlen);
void				ft_all_repeat(t_lem **tlen, t_top **tops);
void				ft_write_repeat(t_lem **tlen, t_top **tops, int c);
void				ft_create_repeat(t_lem **tlen);
/*
**variants
*/
void				ft_go_way(t_lem **tlen, t_top **tops);
void				ft_one_in_stack(t_lem **tlen);
void				ft_kit_kat(t_lem **tlen, int c);
int					ft_only_one(t_lem **tlen, int c);
/*
**no_repeat
*/
void				ft_full_rep(t_lem **tlen, t_top **tops);
void				ft_write_big(t_lem **tlen, int c, int i);
void				ft_no_clones(t_lem **tlen);
void				ft_no_clones_2(t_lem **tlen, int c, int i);
void				ft_check_repeat(t_lem **tlen);
/*
**create_groups
*/
void				ft_tops_groups(t_lem **tlen, t_top **tops);
void				ft_count_len(t_lem **tlen);
void				ft_count_len_2(t_lem **tlen, int c);
void				ft_create_groups(t_lem **tlen);
void				ft_start_group(t_lem **tlen, t_top **tops);
/*
**break_your_mind
*/
void				ft_part(t_lem **tlen, int c, int n, int j);
void				ft_count_break(t_lem **tlen, int c, int j);
void				ft_break_your_mind(t_lem **tlen, t_top **tops, int c);
void				ft_break_1(t_lem **tlen, int c);
int					ft_not_only_one(t_lem **tlen, int c);
#endif
