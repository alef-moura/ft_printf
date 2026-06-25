/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 16:29:40 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/25 17:27:24 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int i;

	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	i = 0;
	while (str[i])
		i++;
	return (write(1, str, i));
}

int ft_putnbr(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

