/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:43:53 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/21 15:08:51 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_printf(const char *type, ...);
int		ft_putstr(char *s);
void	ft_putnbr_u(unsigned int n, int *count);
void	ft_printhex(unsigned int n, int *count, char c);
void	ft_putnbr(int n, int *count);
void	ft_address(unsigned long n, int *count);

#endif
