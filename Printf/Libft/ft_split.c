/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:42:49 by tbartocc          #+#    #+#             */
/*   Updated: 2024/10/11 12:01:53 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_c(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

int	ft_count_words(char const *str, char charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != charset && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*str == charset && in_word)
			in_word = 0;
		str++;
	}
	return (count);
}

char	*ft_strncpy(char *dest, char const *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (dest);
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		len;
	int		k;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	i = 0;
	len = 0;
	k = 0;
	tab = ft_calloc(sizeof(char *), (words + 1));
	while (k < words)
	{
		if (s[i] != c)
		{
			len = ft_strlen_c(s + i, c);
			tab[k] = ft_calloc(sizeof(char), (len + 1));
			ft_strncpy(tab[k++], s + i, len + 1);
			i += len;
		}
		i++;
	}
	return (tab);
}

// int	main(void)
// {
// 	char	**tab;
// 	int		i;

// 	tab = ft_split("    J'ai des espaces avant", ' ');
// 	i = 0;
// 	while (tab[i])
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }
