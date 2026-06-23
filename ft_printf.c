/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:26:43 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/22 17:26:49 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
