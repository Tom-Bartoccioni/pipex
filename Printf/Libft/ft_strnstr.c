/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:53:09 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:37:44 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i[3];

	i[0] = ft_strlen(little);
	if (i[0] == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i[1] = 0;
	while (i[1] <= len - i[0])
	{
		if (big[i[1]] == '\0')
			break ;
		i[2] = 0;
		while (i[2] < i[0])
		{
			if (big[i[1] + i[2]] != little[i[2]])
				break ;
			i[2]++;
		}
		if (i[2] == i[0])
			return ((char *)(big + i[1]));
		i[1]++;
	}
	return (NULL);
}
