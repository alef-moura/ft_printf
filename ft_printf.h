/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 12:42:33 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/25 16:14:13 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#   define FT_PRINTF_H

#   include <stdarg.h>
#   include <unistd.h>

int ft_printf(const char *str, ...);
int ft_check_format(char c, va_list args);

int ft_putchar(int c);
int ft_putstr(char *str);
int ft_putnbr();
int ft_putnbr_unsigned();
int ft_puthex();
int ft_putptr();

#endif
