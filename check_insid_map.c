/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_insid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:31 by abel-bou          #+#    #+#             */
/*   Updated: 2022/03/04 20:55:59 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_inside_wall(t_map *st)
{
	st->m_x = 1;
	st->move = 0;
	st->cou_p = 0;
	st->cou_c = 0;
	while (st->m_x < st->n_col - 1)
	{
		st->m_y = 1;
		while (st->m_y < st->n_row - 1)
		{
			if (st->m_l[st->m_x][st->m_y] != '0' &&
			st->m_l[st->m_x][st->m_y] != '1' &&
			st->m_l[st->m_x][st->m_y] != 'C' &&
			st->m_l[st->m_x][st->m_y] != 'P' &&
			st->m_l[st->m_x][st->m_y] != 'E')
			{
				perror("Error\nThere is wrong in your map!");
				exit(0);
			}
			count_c_p(st);
			st->m_y++;
		}
		st->m_x++;
	}
	check_p_c_e(st);
}

void	count_c_p(t_map *st)
{
	if (st->m_l[st->m_x][st->m_y] == 'C')
	{
		st->check[0] = 'C';
		st->cou_c++;
	}
	if (st->m_l[st->m_x][st->m_y] == 'P')
	{
		st->check[1] = 'P';
		st->cou_p++;
	}
	if (st->m_l[st->m_x][st->m_y] == 'E')
		st->check[2] = 'E';
}

void	check_p_c_e(t_map *st)
{
	if (st->cou_p > 1)
	{
		perror("Error\nThere are many Players");
		exit(0);
	}
	if (st->check[0] != 'C' || st->check[1] != 'P' || st->check[2] != 'E')
	{
		perror("Error\nYou need 'C' or 'P' or 'E'");
		exit(0);
	}
}

int	sed(void)
{
	exit(0);
	return (0);
}
