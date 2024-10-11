/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:25:17 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:36:46 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len[3];
	size_t	i;

	len[0] = 0;
	len[1] = 0;
	if (s1)
		len[0] = ft_strlen(s1);
	if (s2)
		len[1] = ft_strlen(s2);
	len[2] = len[0] + len[1];
	joined_str = malloc(sizeof(char) * (len[2] + 1));
	if (!joined_str)
		return (NULL);
	i = -1;
	if (s1)
		while (++i < len[0])
			joined_str[i] = s1[i];
	i = -1;
	if (s2)
		while (++i < len[1])
			joined_str[len[0] + i] = s2[i];
	joined_str[len[2]] = '\0';
	return (joined_str);
}
