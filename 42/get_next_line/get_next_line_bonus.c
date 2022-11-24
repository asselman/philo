/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasselma <aasselma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:49:17 by aasselma          #+#    #+#             */
/*   Updated: 2022/11/24 22:11:55 by aasselma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		i;
	int		r;

	r = 0;
	i = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	while (1)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			free(buffer);
			if (str)
				free(str);
			return (NULL);
		}
		buffer[r] = '\0';
		str = ft_strjoin(str, buffer);
		if ((check_str(buffer) == 1) || (r == 0))
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line;
	int			len;

	len = 0;
	if (fd < 0)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!(str[fd]))
		return (NULL);
	line = ft_getline(str[fd], &len);
	str[fd] = ft_getafterline(str[fd], len);
	return (line);
}
