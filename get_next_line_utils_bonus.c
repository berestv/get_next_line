/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:34:52 by bbento-e          #+#    #+#             */
/*   Updated: 2023/01/18 10:34:17 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)str;
	while (aux[i] != c && aux[i] != '\0')
		i++;
	if (aux[i] == '\0')
	{
		if (c != '\0')
			return (NULL);
		else
			return (aux);
	}
	i++;
	return (aux + i);
}

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*aux;
	size_t	i;

	i = 0;
	if (!nmemb | !size)
		return (NULL);
	aux = malloc(nmemb * size);
	if (!aux)
		return (NULL);
	while (i < (nmemb * size))
		*(aux + i++) = '\0';
	return ((void *)aux);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	size_t	len;
	int		i;
	int		a;

	i = 0;
	a = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	aux = ft_calloc(sizeof(char), (len + 1));
	if (!aux)
		return (NULL);
	while (s1 && s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	while (s2 && s2[a])
		aux[i++] = s2[a++];
	aux[i] = '\0';
	return (aux);
}
