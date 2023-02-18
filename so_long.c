/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:40:31 by abel-bou          #+#    #+#             */
/*   Updated: 2022/03/04 20:58:26 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *name)
{
	int		len;
	char	*ext;

	ext = ".ber";
	len = ft_strlen(name);
	if (ft_strcmp(&name[len - 4], ext))
	{	
		perror("Error\nYour map's extension is wrong");
		exit(0);
	}
}

void	read_map(t_map *st, char *name_f)
{
	char	*line;

	st->fd = open(name_f, O_RDONLY);
	if (st->fd < 0)
	{
		perror("Error\nDoes not exist fd");
		exit(0);
	}
	line = get_next_line(st->fd);
	if (!line)
	{
		perror("Error\nThe map is empty");
		exit(0);
	}
	while (line)
	{
		free(line);
		line = get_next_line(st->fd);
		st->n_col++;
	}
	close(st->fd);
	st->m_l = malloc(sizeof(char *) * st->n_col);
	if (!st->m_l)
		exit(0);
	sides_map(st, name_f);
}

void	sides_map(t_map *st, char *name_f)
{
	int	i;

	st->fd = open(name_f, O_RDONLY);
	i = 0;
	while (i < st->n_col)
	{
		st->m_l[i] = get_next_line(st->fd);
		if (st->m_l[i][0] != '1'
		|| st->m_l[i][ft_strlen(st->m_l[i]) - 1] != '1'
		|| ft_strlen(st->m_l[0]) != ft_strlen(st->m_l[i]))
		{
			perror("Error\nThere is wrong in your wall");
			exit(0);
		}
		i++;
	}
	above_under_map(st);
}

void	above_under_map(t_map *st)
{
	st->n_row = 0;
	while (st->m_l[0][st->n_row]
		|| st->m_l[st->n_col - 1][st->n_row])
	{
		if (st->m_l[0][st->n_row] != '1'
			|| st->m_l[st->n_col - 1][st->n_row] != '1')
		{
			perror("Error\nThere are wrong in your first wall or last");
			exit(0);
		}
		st->n_row++;
	}
	check_inside_wall(st);
}

int	main(int argc, char **argv)
{
	t_map	st;

	st.n_col = 0;
	if (argc != 2)
	{
		perror("Error\nGive me one map");
		exit(0);
	}
	check_extension(argv[1]);
	read_map(&st, argv[1]);
	st.mlx = mlx_init();
	st.win = mlx_new_window(st.mlx, st.n_row * 50, st.n_col * 50, "so_long");
	check_put_img(&st);
	mlx_key_hook(st.win, keyboards, &st);
	mlx_hook(st.win, 17, 0, sed, &st);
	mlx_loop(st.mlx);
}
