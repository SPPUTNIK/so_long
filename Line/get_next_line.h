/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:05:23 by abel-bou          #+#    #+#             */
/*   Updated: 2022/02/24 15:17:53 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *s);
int		ft_strchr(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_all_after_line(char	*sal);
char	*give_one_line(char *sal);
char	*ft_give_line(int fd, char *sal);

#endif
