/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:00:48 by tbartocc          #+#    #+#             */
/*   Updated: 2024/07/08 16:40:41 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	switchcase(char c, va_list args, int *res)
{
	if (c == 'c')
		case_c(args, res);
	else if (c == 's')
		case_s(args, res);
	else if (c == 'p')
		case_p(args, res);
	else if (c == 'd')
		case_d(args, res);
	else if (c == 'i')
		case_i(args, res);
	else if (c == 'u')
		case_u(args, res);
	else if (c == 'x')
		case_x(args, res);
	else if (c == 'X')
		case_x_upper(args, res);
	else if (c == '%')
		case_percent(res);
}

int	ft_printf(const char *line, ...)
{
	int		i;
	int		res;
	va_list	args;

	va_start(args, line);
	i = 0;
	res = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '%')
		{
			ft_putchar(line[i]);
			res++;
		}
		else
			switchcase(line[++i], args, &res);
		i++;
	}
	va_end(args);
	return (res);
}
