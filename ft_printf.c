/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:26:43 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/24 22:13:00 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_format(char c, va_list args)
{
	int  count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	size_t  i;
	int  count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		else
		{
			i++;
			if (format[i])
				count += ft_check_format(format[i], args);
			else
				break ;
		}
		i++;
	}
	va_end(args);
	return (count);
}





































#include "ft_printf.h"

static int	ft_checks(va_list *list, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*list, int)));
	if (c == 's')
		return (ft_putstr(va_arg(*list, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(*list, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*list, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*list, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(*list, unsigned int), c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += (ft_putchar('%'));
			else
				count += ft_checks(&list, format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
