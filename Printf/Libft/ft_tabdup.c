/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbartocc <tbartocc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:21:04 by tbartocc          #+#    #+#             */
/*   Updated: 2024/09/18 13:06:48 by tbartocc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**dup;
	int		i;
	int		len;

	if (!tab)
		return (NULL);
	i = -1;
	while (tab && tab[++i] != NULL)
		;
	dup = ft_calloc(sizeof(char *), (i + 1));
	i = -1;
	while (tab && tab[++i] != NULL)
	{
		len = ft_strlen(tab[i]);
		dup[i] = ft_strdup(tab[i]);
	}
	return (dup);
}
