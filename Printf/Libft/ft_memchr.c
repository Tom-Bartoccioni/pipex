/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 00:16:32 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:35:45 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;
	size_t				i;

	p = s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == uc)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
