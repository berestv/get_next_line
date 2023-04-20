/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:34:39 by bbento-e          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:05 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*getline(int fd, char *str)
{
	int		i;
	char	*aux;
	char	*active;

	i = 1;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	active = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (!(ft_strchr(active, '\n')) && i != 0)
	{
		i = read(fd, active, BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			free(active);
			return (NULL);
		}
		active[i] = '\0';
		aux = ft_strjoin(str, active);
		free(str);
		str = aux;
	}
	free(active);
	return (str);
}

static char	*filter(char *str)
{
	int		i;
	char	*filtered;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	filtered = malloc(sizeof(char) * (i + 1 + 1));
	if (!filtered)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		filtered[i] = str[i];
		i++;
	}
	filtered[i] = str[i];
	i++;
	filtered[i] = '\0';
	return (filtered);
}

static char	*recycle(char *str)
{
	int		i;
	int		j;
	char	*recycled;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i] || !str)
	{
		free (str);
		return (NULL);
	}
	recycled = ft_calloc(sizeof(char), (ft_strlen(str) - i));
	if (!recycled)
		return (NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
	{
		recycled[j] = str[i];
		j++;
		i++;
	}
	free (str);
	return (recycled);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[MAX_F_OPEN];

	if (fd < 0 || BUFFER_SIZE <= 0 || MAX_F_OPEN < fd)
		return (NULL);
	str[fd] = getline(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = filter(str[fd]);
	str[fd] = recycle(str[fd]);
	return (line);
}
/* #include <stdio.h>
int	main()
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);

	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);


	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);

	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);

	fd = open("test2", O_RDONLY);
	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);

	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);


	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);

	line = get_next_line(fd);
	printf("%d: %s\n", i++, line);

	return 0;
} */
