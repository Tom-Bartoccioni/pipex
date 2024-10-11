/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:26 by tbartocc          #+#    #+#             */
/*   Updated: 2024/07/08 16:40:50 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include "./Libft/libft.h"

int		ft_printf(const char *line, ...);
void	switchcase(char c, va_list args, int *res);
void	case_percent(int *res);
void	case_c(va_list args, int *res);
void	case_s(va_list args, int *res);
void	case_d(va_list args, int *res);
void	case_i(va_list args, int *res);
void	case_u(va_list args, int *res);
void	case_p(va_list args, int *res);
void	case_x(va_list args, int *res);
void	case_x_upper(va_list args, int *res);

#endif
