/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesferr <alesferr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:24:05 by alesferr          #+#    #+#             */
/*   Updated: 2026/06/26 18:39:46 by alesferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	i += write(1, "0x", 2);
	i += ft_puthex(ptr, 'x');
	return (i);
}
