/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:20:39 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:37:00 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (src_len >= size)
		copy_len = size - 1;
	else
		copy_len = src_len;
	if (size > 0)
	{
		ft_memcpy(dst, src, copy_len);
		dst[copy_len] = '\0';
	}
	return (src_len);
}
