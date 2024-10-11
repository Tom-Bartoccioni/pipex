/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:20:39 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:36:56 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dst_len)
		return (size + src_len);
	i = -1;
	while (++i < src_len && (dst_len + i) < (size - 1))
		dst[dst_len + i] = src[i];
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
