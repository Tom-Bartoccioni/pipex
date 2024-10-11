/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:25:11 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:38:00 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	substr_len = s_len - start;
	if (substr_len > len)
		substr_len = len;
	substr = malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < substr_len)
		substr[i] = s[start + i];
	substr[substr_len] = '\0';
	return (substr);
}
