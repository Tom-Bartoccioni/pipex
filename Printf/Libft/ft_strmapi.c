/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:50:15 by tbartocc          #+#    #+#             */
/*   Updated: 2024/05/21 19:37:16 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		len;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = 0;
	while (s[len] != '\0')
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		result[i] = f(i, s[i]);
	result[len] = '\0';
	return (result);
}
