/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 05:30:26 by abel-bou          #+#    #+#             */
/*   Updated: 2022/03/01 16:41:27 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "./Line/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct parametrs_map
{
	int		fd;
	int		n_row;
	int		n_col;
	int		i;
	int		j;
	char	check[3];
	char	**m_l;
	void	*img;
	void	*win;
	void	*mlx;
	int		w;
	int		h;
	int		p_i;
	int		p_j;
	int		m_x;
	int		m_y;
	int		cou_c;
	int		cou_p;
	int		move;
}t_map;

void	check_extension(char *name);
void	read_map(t_map *st, char *name_f);
void	sides_map(t_map *st, char *name_f);
void	above_under_map(t_map *st);
void	check_inside_wall(t_map *st);
void	count_c_p(t_map *st);
void	check_p_c_e(t_map *st);

void	put_img(t_map *st, char *path);
void	check_put_img(t_map *st);

int		keyboards(int n_key, t_map *st);
void	move_to_right(t_map *st);
void	move_to_left(t_map *st);
void	move_to_up(t_map *st);
void	move_to_down(t_map *st);
int		sed(void);

#endif