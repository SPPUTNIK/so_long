/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:05:35 by abel-bou          #+#    #+#             */
/*   Updated: 2022/02/24 14:49:45 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	after_por(char c, va_list arg)
{
	int	size;

	size = 0;
	if (c == '%')
		size = ft_putchar('%');
	if (c == 'c')
		size = ft_putchar(va_arg(arg, int));
	if (c == 's')
		size = ft_putstr(va_arg(arg, char *));
	if (c == 'd' || c == 'i')
		size = ft_putnbr(va_arg(arg, int));
	if (c == 'p')
	{
		size = ft_putstr("0x");
		size += ft_pointer(va_arg(arg, unsigned long long), "0123456789abcdef");
	}
	if (c == 'x')
		size = ft_base_hex(va_arg(arg, unsigned int), "0123456789abcdef");
	if (c == 'X')
		size = ft_base_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (c == 'u')
		size = ft_uns_base(va_arg(arg, unsigned int));
	return (size);
}

int	ft_printf(const char *forma, ...)
{
	va_list	argm;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(argm, forma);
	while (forma[i])
	{
		if (forma[i] == '%')
		{
			size += after_por(forma[i + 1], argm);
			i += 2;
		}
		else
		{
			ft_putchar(forma[i]);
			size++;
			i++;
		}
	}
	va_end(argm);
	return (size);
}
