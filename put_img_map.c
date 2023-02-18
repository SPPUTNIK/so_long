/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:31 by abel-bou          #+#    #+#             */
/*   Updated: 2022/02/28 15:44:08 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_map *st, char *path)
{
	st->img = mlx_xpm_file_to_image(st->mlx, path, &st->w, &st->h);
	mlx_put_image_to_window(st->mlx, st->win, st->img, st->j * 50, st->i * 50);
}

void	check_put_img(t_map *st)
{
	st->i = 0;
	while (st->i < st->n_col)
	{
		st->j = 0;
		while (st->j < st->n_row)
		{
			if (st->m_l[st->i][st->j] == '1')
				put_img(st, "./ham/wall.xpm");
			if (st->m_l[st->i][st->j] == 'C')
				put_img(st, "./ham/Colec.xpm");
			if (st->m_l[st->i][st->j] == 'E')
				put_img(st, "./ham/exit.xpm");
			if (st->m_l[st->i][st->j] == 'P')
			{
				put_img(st, "./ham/Player.xpm");
				st->p_i = st->i * 50;
				st->p_j = st->j * 50;
			}
			st->j++;
		}
		st->i++;
	}
}
