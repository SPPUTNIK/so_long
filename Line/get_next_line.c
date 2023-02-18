/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:04:05 by abel-bou          #+#    #+#             */
/*   Updated: 2022/03/01 15:46:25 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_all_after_line(char	*sal)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (sal[i] && sal[i] != '\n')
		i++;
	if (sal[i] == 0)
	{
		free(sal);
		return (NULL);
	}
	new_str = malloc(sizeof(char) * ft_strlen(sal) - i + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (sal[i++])
	{
		new_str[j] = sal[i];
		j++;
	}
	new_str[j] = '\0';
	free(sal);
	return (new_str);
}

char	*ft_give_one_line(char *sal)
{
	int		i;
	char	*new_str;

	i = 0;
	while (sal[i] && sal[i] != '\n')
		i++;
	if (sal[i] == '\0')
		new_str = malloc(sizeof(char) * (i + 1));
	else
		new_str = malloc(sizeof(char) * (i + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (sal[i] && sal[i] != '\n')
	{
		new_str[i] = sal[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_give_line(int fd, char *sal)
{
	char	*buf;
	int		byte;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	byte = 1;
	while (!ft_strchr(sal) && byte > 0)
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buf);
			free(sal);
			return (NULL);
		}
		buf[byte] = '\0';
		sal = ft_strjoin(sal, buf);
	}
	free(buf);
	return (sal);
}

char	*get_next_line(int fd)
{
	char		*l;
	static char	*sal;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!sal)
	{
		sal = malloc(sizeof(char) * 1);
		if (!sal)
			return (NULL);
		sal[0] = '\0';
	}
	sal = ft_give_line(fd, sal);
	if (!sal)
		return (NULL);
	if (sal[0] == '\0')
	{
		free(sal);
		sal = NULL;
		return (NULL);
	}
	l = ft_give_one_line(sal);
	sal = ft_all_after_line(sal);
	return (l);
}
