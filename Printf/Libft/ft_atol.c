/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:43:02 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/03 16:13:21 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		sign;
	int		i;
	long	res;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '0')
		i++;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (ft_strlen(str + i) > 11)
		return ((long) INT_MAX + 1);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return ((long) INT_MAX + 1);
	}
	res *= sign;
	return (res);
}
