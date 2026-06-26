/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:56:51 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/26 18:38:18 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
		i += ft_putnbr_unsigned(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
