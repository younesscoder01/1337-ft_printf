/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:11 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/14 11:48:05 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int n, int *count, char c)
{
	char	*strhex;
	char	*strhexu;

	strhex = "0123456789abcdef";
	strhexu = "0123456789ABCDEF";
	if (n == 0)
		*count += write(1, "0", 1);
	if (c == 'x')
	{
		if (n > 0)
		{
			ft_printhex(n / 16, count, c);
			write(1, &strhex[n % 16], 1);
			*count += 1;
		}
	}
	else if (c == 'X')
	{
		if (n > 0)
		{
			ft_printhex(n / 16, count, c);
			write(1, &strhexu[n % 16], 1);
			*count += 1;
		}
	}
}
