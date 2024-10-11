/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:51:41 by tbartocc          #+#    #+#             */
/*   Updated: 2024/07/08 16:40:59 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	case_percent(int *res)
{
	ft_putchar('%');
	*res += 1;
}

void	case_c(va_list args, int *res)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	*res += 1;
}

void	case_s(va_list args, int *res)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		*res += 6;
		return ;
	}
	ft_putstr(str);
	*res += ft_strlen(str);
}

void	case_d(va_list args, int *res)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	ft_putnbr(nb);
	len = 0;
	if (nb == 0)
		len = 1;
	else
	{
		if (nb < 0)
		{
			if (nb == -2147483648)
				nb = 2147483647;
			else
				nb = -nb;
			len++;
		}
		while (nb > 0)
		{
			nb /= 10;
			len++;
		}
	}
	*res += len;
}

void	case_i(va_list args, int *res)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	ft_putnbr(nb);
	len = 0;
	if (nb == 0)
		len = 1;
	else
	{
		if (nb < 0)
		{
			if (nb == -2147483648)
				nb = 2147483647;
			else
				nb = -nb;
			len++;
		}
		while (nb > 0)
		{
			nb /= 10;
			len++;
		}
	}
	*res += len;
}
