/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:38 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/06 09:38:07 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

int		ft_check_end(char *buffer);
char	*ft_check_buffer(char *buffer);

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*output;
	size_t	buffersize;

	buffer = NULL;
	output = NULL;
	buffersize = 5;
	while (ft_check_end(buffer) == 0)
	{
		read(fd, buffer, buffersize);
		output = (ft_strjoin(output, ft_check_buffer(buffer)));
	}
	return (output);
}

int	ft_check_end(char *buffer)
{
	size_t	i;

	i = 0;
	while (ft_strlen(buffer) >= i)
	{
		if (buffer[i] == '\0')
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_check_buffer(char *buffer)
{
	static char		*static_buffer = NULL;
	static size_t	i = 0;
	static size_t	start = 0;
	char			*last;

	if (static_buffer == NULL)
	{
		static_buffer = buffer;
		start = 0;
	}
	else
		start += i;
	i = 0;
	while (*static_buffer != '\0')
	{
		if (*static_buffer == '\n')
			return (ft_substr(buffer, start, i));
		else
		{
			static_buffer++;
			i++;
		}
	}
	last = ft_substr(buffer, start, i);
	static_buffer = NULL;
	i = 0;
	return (last);
}
