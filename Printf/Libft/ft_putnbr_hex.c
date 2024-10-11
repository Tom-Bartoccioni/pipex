/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:27:56 by tbartocc          #+#    #+#             */
/*   Updated: 2024/07/05 14:40:54 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_hex(unsigned long num)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (num >= 16)
		ft_putnbr_hex(num / 16);
	ft_putchar(hex_digits[num % 16]);
}

void	ft_putnbr_hex_upper(unsigned long num)
{
	char	*hex_digits;

	hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		ft_putnbr_hex_upper(num / 16);
	ft_putchar(hex_digits[num % 16]);
}
