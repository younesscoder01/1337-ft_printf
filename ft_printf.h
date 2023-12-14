/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:43:53 by ysahraou          #+#    #+#             */
/*   Updated: 2023/12/14 11:25:08 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
void	ft_putnbr_u(unsigned int n, int *count);
void	ft_printhex(unsigned int n, int *count, char c);
void	ft_putnbr(int n, int *count);
void	ft_address(unsigned long n, int *count);

#endif
