/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:11 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/13 15:04:48 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(int n, int *count, char c)
{
	char	*strhex;
	char	*strhexu;

	strhex = "0123456789abcdef";
	strhexu = "0123456789ABCDEF";
	if (c == 'x')
	{
		while (n > 0)
		{
			ft_printhex(n / 10, count, c);
			write(1, &strhex[n % 10], 1);
			*count += 1;
		}
	}
	if (c == 'X')
	{
		while (n > 0)
		{
			ft_printhex(n / 10, count, c);
			write(1, &strhexu[n % 10], 1);
			*count += 1;
		}
	}
}
