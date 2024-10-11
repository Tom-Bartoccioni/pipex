/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:29:10 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:35:43 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*convert_to_string(int n, int num_digits, int sign)
{
	char	*result;
	int		index;

	result = malloc(sizeof(char) * (num_digits + 1));
	if (result == NULL)
		return (NULL);
	index = num_digits - 1;
	if (n == 0)
		result[index--] = '0';
	else
	{
		while (n != 0)
		{
			result[index--] = '0' + ft_abs(n % 10);
			n /= 10;
		}
	}
	if (sign == -1)
		result[0] = '-';
	result[num_digits] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int	sign;
	int	num_digits;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	num_digits = count_digits(n);
	if (sign == -1)
		num_digits++;
	return (convert_to_string(n, num_digits, sign));
}
