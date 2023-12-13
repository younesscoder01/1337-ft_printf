/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:51:33 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/13 14:37:31 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_address(int num, int *count)
{
	*count += write(1, "0x", 2);
	ft_printhex(num, count, 'x');
}

static void	ft_check_f(char f, va_list args, int *count)
{
	if (f == 'c')
		*count += ft_putchar(va_arg(args, int ));
	else if (f == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (f == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (f == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (f == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (f == 'x')
		ft_printhex(va_arg(args, int), count, 'x');
	else if (f == 'X')
		ft_printhex(va_arg(args, int), count, 'X');
	else if (f == 'p')
		ft_address(va_arg(args, int), count);
	else if (f == '%')
		*count += ft_putchar('%');
	else
	{
		*count += write(1, "%", 1);
		*count += write(1, &f, 1);
	}
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		count;

	va_start(args, type);
	count = 0;
	while (*type)
	{
		if (*type == '%')
		{
			type++;
			ft_check_f(*type, args, &count);
		}
		else
		{
			write(1, type, 1);
			count++;
		}
		type++;
	}
	return (count);
}
