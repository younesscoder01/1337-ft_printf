/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:03:02 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/14 11:26:20 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_address(unsigned long n, int *count)
{
	char	*strhex;

	strhex = "0123456789abcdef";
	if (n > 0)
	{
		ft_address(n / 16, count);
		write(1, &strhex[n % 16], 1);
		*count += 1;
	}
}
