/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:38 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/13 05:01:43 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

char	*ft_check_buf(char *t_buf);
char	*ft_edit_buf(char *t_buf);
int		ft_newline(char *buffer);

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*t_buf = NULL;
	char			*out;
	int				s_read;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buf == NULL)
		return (NULL);
	s_read = 1;
	while (s_read != 0 && !ft_newline(t_buf))
	{
		s_read = read(fd, buf, BUFFER_SIZE);
		if (s_read == -1)
		{
			free(buf);
			free(t_buf);
			return (NULL);
		}
		if (s_read != 0)
			t_buf = ft_strjoin(t_buf, buf);
	}
	free(buf);
	out = ft_check_buf(t_buf);
	t_buf = ft_edit_buf(t_buf);
	return (out);
}

char	*ft_check_buf(char *t_buf)
{
	int		i;
	char	*out;

	i = 0;
	while (t_buf[i] != '\n' && t_buf[i] != '\0')
		i++;
	out = ft_substr(t_buf, 0, i);
	return (out);
}

char	*ft_edit_buf(char *t_buf)
{
	int		i;
	char	*out;

	i = 0;
	while (t_buf[i] != '\n' && t_buf[i] != '\0')
		i++;
	out = ft_substr(t_buf, i + 1, ft_strlen(t_buf) - (i + 1));
	free(t_buf);
	return (out);
}

int	ft_newline(char *t_buf)
{
	if (t_buf == NULL)
		return (0);
	while (*t_buf != '\0')
	{
		if (*t_buf == '\n')
			return (1);
		t_buf++;
	}
	return (0);
}

	// 	if (!ft_newline(t_buf))
	// 	{
	// 		t_buf = buf;
	// 		out = ft_substr(t_buf, 0, ft_newline(t_buf));
	// 		t_buf = ft_substr(t_buf, ft_newline(t_buf) + 1, s_read);
	// 		return (out);
	// 	}
	// 	if (s_read == BUFFER_SIZE)
	// 	{
	// 		t_buf = buf;
	// 		out = ft_substr(t_buf, 0, ft_newline(t_buf));
	// 		t_buf = ft_substr(t_buf, ft_newline(t_buf) + 1, s_read);
	// 		return (out);
	// 	}
	// 	// if (s_read < BUFFER_SIZE)
	// 	// 	}

	// return (NULL);

	// s_read = read(fd, buf, BUFFER_SIZE);
	// t_buf = buf;
	// while (!ft_newline(t_buf) && s_read > 0)
	// {
		// t_buf = ft_strjoin(t_buf, buf);
		// if (ft_newline(t_buf) > 0)
		// {
		// 	out = ft_substr(t_buf, 0, ft_newline(t_buf));
		// 	t_buf = ft_substr(t_buf, (int)ft_newline(t_buf), s_read - ft_newline(t_buf));
		// 	return (out);
		// }
		// return (t_buf);
	// }

	// while ((int_read > 0) && (!ft_strrchr(s_buffer, '\n')))
	// {
	// 	s_buffer = ft_strjoin(s_buffer, buffer);
	// 	// int_read = read(fd, buffer, BUFFER_SIZE);
	// }
	// if (int_read == -1)
	// 	return (NULL);
	// output = NULL;
	// output = transfer_buffer;
	// transfer_buffer = ft_strdup(ft_strrchr(transfer_buffer, '\n'));
	// ft_strrchr(output, '\n')[1] = '\0';
	// return (output);

// ********felix**************
// char *gnl(int fd)
// {
	// char *s = malloc(10000), *c = s;
	// while(read(fd, c, 1) > 0 && *c++ != '\n');
	// return c > s ? (*c = '\0', s) : (free(s), NULL);
// }

// char * buf;
// static char *leftover = NULL;

// buf alllociert

// while (!ft_strrchr(leftover, '\n') && read(fd, buf, BUFFER_SIZE) > 0)
	// leftover = ft_strjoinfree(leftover, buf);
	// read_result == -1

// char * res = leftover;
// leftover = ft_strdup(ft_strrchr(leftover, '\n') + 1);
// ft_strrchr(res, '\n')[1] = '\0';
// return (res);

// *********Sonntag Nacht**********
// while ((int_read > 0) && (!ft_strrchr(transfer_buffer, '\n')))
// 	{
// 		transfer_buffer = ft_strjoin(transfer_buffer, buffer);

// 		if (transfer_buffer != NULL)
// 		{
// 			buffer = ft_strjoin(transfer_buffer, buffer);
// 			free(transfer_buffer);
// 		}
// 		if (ft_found_newline(buffer) != NULL)
// 		{
// 			output = ft_substr(buffer, 0, (size_t)(ft_found_newline(buffer) - buffer));
// 			buffer = ft_substr(buffer, (size_t)(ft_found_newline(buffer) - buffer) + 1, ft_strlen(buffer));
// 			return (output);
// 		}
// 		else
// 		{
// 			while (len == BUFFER_SIZE)
// 			{
// 				output = ft_strjoin(output, ft_substr(buffer, 0, len));
// 				len = read(fd, buffer, BUFFER_SIZE);
// 			}
// 			output = ft_strjoin(output, ft_substr(buffer, 0, len));
// 			return (output);
// 		}
// 	}
// 	return (NULL);

// *************Second approach***********
// char	*get_next_line(int fd)
// {
// 	char		*buffer;
// 	char		*output;
// 	int			len;

// 	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
// 	if (buffer == NULL)
// 		return (NULL);
// 	len = 0;
// 	output = NULL;
// 	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
// 	{
// 		len = ft_strlen(buffer);
// 		if (ft_found_newline(buffer) > 0)
// 		output = ft_check_buffer(buffer, len);
// 		else
// 		output = ft_check_buffer_without_newline(buffer, len, fd);
// 		return (output);
// 	}
// 	// read(fd, buffer, BUFFER_SIZE);
// 	// len = ft_strlen(buffer);
// 	// if (ft_found_newline(buffer) > 0)
// 	// 	output = ft_check_buffer(buffer, len);
// 	// else
// 	// 	output = ft_check_buffer_without_newline(buffer, len, fd);
// 	return (output);
// }

// char	*ft_check_buffer_without_newline(char *buffer, int len, int fd)
// {
// 	char	*output;

// 	output = NULL;
// 	while (len == BUFFER_SIZE)
// 	{
// 		output = ft_strjoin(output, ft_substr(buffer, 0, len));
// 		len = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	// output = ft_strjoin(output, ft_substr(buffer, 0, len));
// 	return (output);
// }

// char	*ft_check_buffer(char *buffer, int len)
// {
// 	static char		*read_buffer = NULL;
// 	static char		*buffer_transfer = NULL;
// 	char			*output;
// 	static size_t	i = 0;

// 	output = NULL;
// 	if (buffer_transfer != NULL)
// 	{
// 		read_buffer = ft_strjoin(buffer_transfer, buffer);
// 		buffer_transfer = NULL;
// 	}
// 	while (read_buffer[i] != '\0')
// 	{
// 		if (read_buffer[i] == '\n')
// 		{
// 			output = ft_substr(read_buffer, 0, i);
// 			i++;
// 			read_buffer = ft_substr(read_buffer, i, len);
// 			return (output);
// 		}
// 		i++;
// 	}
// 	buffer_transfer = ft_substr(read_buffer, i, len);
// 	read_buffer = NULL;
// 	i = 0;
// 	return (NULL);
// }

// 	if (static_buffer == NULL)
// 	{
// 		static_buffer = buffer;
// 		start = 0;
// 	}
// 	else
// 	{
// 		start += i + 1;
// 		static_buffer++;
// 	}
// 	i = 0;
// 	while (*static_buffer != '\0')
// 	{
// 		if (*static_buffer == '\n')
// 		{
// 			// if (buffer_transfer != NULL)
// 			// {
// 			// 	return (ft_strjoin(buffer_transfer, ft_substr(buffer, start, i)));
// 			// 	free(buffer_transfer);
// 			// }
// 			// else
// 				// return (ft_substr(buffer, start, i));
// 		}
// 		else
// 		{
// 			static_buffer++;
// 			i++;
// 		}
// 	}
// 	buffer_transfer = ft_substr(buffer, start, i);
// 	static_buffer = NULL;
// 	start = 0;
// 	i = 0;
// 	return (buffer);
// }

// **************First Try**************

// char	*ft_check_buffer(char *buffer, int len, int fd)
// {
	// static char		*static_buffer = NULL;
	// static char		*buffer_transfer = NULL;
	// char			*output = NULL;
	// static size_t	i = 0;
	// static size_t	start = 0;

	// while (len == BUFFER_SIZE)
	// {
		// while (buffer[i] != '\0')
		// {
		// 	if (*buffer == '\n')
		// 	{
		// 		output = ft_substr(buffer, start, ((i + 1) - start));
		// 		i++;
		// 		printf("%zu\n", i);
		// 		return (output);
		// 	}
		// i++;
		// }

// 		output = ft_strjoin(output, ft_substr(buffer, start, len));
// 		len = read(fd, buffer, BUFFER_SIZE);
// 	}
// 	output = ft_strjoin(output, ft_substr(buffer, start, len));
// 	start = 0;
// 	i = 0;
// 	return (output);
// }
