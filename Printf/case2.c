/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:51:41 by tbartocc          #+#    #+#             */
/*   Updated: 2024/07/05 15:18:51 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	case_u(va_list args, int *res)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(args, unsigned int);
	ft_putnbr_unsigned(nb);
	len = 0;
	if (nb == 0)
		len = 1;
	else
	{
		while (nb > 0)
		{
			nb /= 10;
			len++;
		}
	}
	*res += len;
}

void	case_p(va_list args, int *res)
{
	unsigned long	addr;
	int				len;

	addr = va_arg(args, unsigned long);
	if (addr == 0)
	{
		*res += 5;
		ft_putstr("(nil)");
		return ;
	}
	len = 2;
	ft_putstr("0x");
	ft_putnbr_hex(addr);
	while (addr > 0)
	{
		addr /= 16;
		len++;
	}
	*res += len;
}

void	case_x(va_list args, int *res)
{
	unsigned long	nb;
	int				len;

	nb = va_arg(args, unsigned);
	ft_putnbr_hex(nb);
	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	*res += len;
}

void	case_x_upper(va_list args, int *res)
{
	unsigned long	nb;
	int				len;

	nb = va_arg(args, unsigned);
	ft_putnbr_hex_upper(nb);
	len = 0;
	if (nb == 0)
		len = 1;
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	*res += len;
}
