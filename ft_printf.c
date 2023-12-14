/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:51:33 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/14 13:04:30 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	put_address(unsigned long num, int *count)
{
	if (num == 0)
	{
		*count += write(1, "(nil)", 5);
	}
	else
	{
		*count += write(1, "0x", 2);
		ft_address(num, count);
	}
}

static void put_hex(unsigned int n, int *count, char c)
{
	if (n == 0)
		*count += write(1, "0", 1);
	else
		ft_printhex(n, count, c);
}

static void	ft_check_f(char f, va_list args, int *count)
{
	if (f == 'c')
		*count += ft_putchar(va_arg(args, int ));
	else if (f == 's')
		*count += ft_putstr(va_arg(args, char *));
	else if (f == 'd' || f == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (f == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), count);
	else if (f == 'x' || f == 'X')
		put_hex(va_arg(args, int), count, f);
	else if (f == 'p')
		put_address(va_arg(args, unsigned long int), count);
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
			if (*type == '\0')
				return (-1);
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
