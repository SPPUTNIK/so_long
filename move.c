/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:31 by abel-bou          #+#    #+#             */
/*   Updated: 2022/03/01 16:05:42 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_right(t_map *st)
{
	if (st->m_l[st->p_i / 50][(st->p_j + 50) / 50] != '1'
	&& st->m_l[st->p_i / 50][(st->p_j + 50) / 50] != 'E')
		ft_printf("%d\n", ++st->move);
	if (st->m_l[st->p_i / 50][(st->p_j + 50) / 50] != '1'
	&& (st->m_l[st->p_i / 50][(st->p_j + 50) / 50] != 'E'
	|| st->cou_c == 0))
	{
		if (st->m_l[(st->p_i) / 50][(st->p_j) / 50] == 'C')
		{
			st->cou_c -= 1;
			st->m_l[(st->p_i) / 50][(st->p_j) / 50] = '0';
		}
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/free.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img, st->p_j, st->p_i);
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/Player.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img,
			st->p_j += 50, st->p_i);
	}
}

void	move_to_left(t_map *st)
{
	if (st->m_l[st->p_i / 50][(st->p_j - 50) / 50] != '1'
	&& st->m_l[st->p_i / 50][(st->p_j - 50) / 50] != 'E')
		ft_printf("%d\n", ++st->move);
	if (st->m_l[st->p_i / 50][(st->p_j - 50) / 50] != '1'
	&& (st->m_l[st->p_i / 50][(st->p_j - 50) / 50] != 'E'
	|| st->cou_c == 0))
	{
		if (st->m_l[(st->p_i) / 50][(st->p_j) / 50] == 'C')
		{
			st->cou_c -= 1;
			st->m_l[(st->p_i) / 50][(st->p_j) / 50] = '0';
		}
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/free.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img, st->p_j, st->p_i);
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/Player.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img,
			st->p_j -= 50, st->p_i);
	}
}

void	move_to_up(t_map *st)
{
	if (st->m_l[(st->p_i - 50) / 50][st->p_j / 50] != '1'
	&& st->m_l[(st->p_i - 50) / 50][st->p_j / 50] != 'E')
		ft_printf("%d\n", ++st->move);
	if (st->m_l[(st->p_i - 50) / 50][st->p_j / 50] != '1'
	&& (st->m_l[(st->p_i - 50) / 50][st->p_j / 50] != 'E'
	|| st->cou_c == 0))
	{
		if (st->m_l[(st->p_i) / 50][(st->p_j) / 50] == 'C')
		{
			st->cou_c -= 1;
			st->m_l[(st->p_i) / 50][(st->p_j) / 50] = '0';
		}
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/free.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img, st->p_j, st->p_i);
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/Player.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img,
			st->p_j, st->p_i -= 50);
	}
}

void	move_to_down(t_map *st)
{
	if (st->m_l[(st->p_i + 50) / 50][st->p_j / 50] != '1'
	&& st->m_l[(st->p_i + 50) / 50][st->p_j / 50] != 'E')
		ft_printf("%d\n", ++st->move);
	if (st->m_l[(st->p_i + 50) / 50][st->p_j / 50] != '1'
	&& (st->m_l[(st->p_i + 50) / 50][st->p_j / 50] != 'E'
	|| st->cou_c == 0))
	{
		if (st->m_l[(st->p_i) / 50][(st->p_j) / 50] == 'C')
		{
			st->cou_c -= 1;
			st->m_l[(st->p_i) / 50][(st->p_j) / 50] = '0';
		}
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/free.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img, st->p_j, st->p_i);
		st->img = mlx_xpm_file_to_image(st->mlx, "./ham/Player.xpm",
				&st->w, &st->h);
		mlx_put_image_to_window(st->mlx, st->win, st->img,
			st->p_j, st->p_i += 50);
	}
}

int	keyboards(int n_key, t_map *st)
{
	if (n_key == 53 || n_key == 12)
		exit(0);
	if (n_key == 2 || n_key == 124)
		move_to_right(st);
	if (n_key == 0 || n_key == 123)
		move_to_left(st);
	if (n_key == 13 || n_key == 126)
		move_to_up(st);
	if (n_key == 1 || n_key == 125)
		move_to_down(st);
	if (st->m_l[(st->p_i) / 50][(st->p_j) / 50] == 'E' && st->cou_c == 0)
	{
		ft_printf("%d\n", ++st->move);
		exit(0);
	}
	return (1);
}
