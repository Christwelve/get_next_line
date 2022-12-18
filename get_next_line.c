/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:38 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/18 21:13:37 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_handle_buf(char *t_buf, int i);
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
		if (s_read < 1 && t_buf == NULL)
			return (free(buf), free(t_buf), NULL);
		if (s_read != 0)
		{
			t_buf = ft_strjoin(t_buf, buf, s_read);
			if (t_buf == NULL)
				return (free(buf), NULL);
		}
	}
	free(buf);
	out = ft_handle_buf(t_buf, 0);
	if (out == NULL)
		return (free(t_buf), NULL);
	t_buf = ft_handle_buf(t_buf, 1);
	if (t_buf == NULL && out == NULL)
		return (NULL);
	if (out != NULL)
		return (out);
	else
		return (NULL);
}

// **********************************************
//  x == 0 cut out until \n     x == 1 edit t_buf
// **********************************************
char	*ft_handle_buf(char *t_buf, int x)
{
	int		i;
	char	*out;

	i = 0;
	if (t_buf[i] == '\0')
		return (NULL);
	while (t_buf[i] != '\n' && t_buf[i] != '\0')
		i++;
	if (x == 0)
		out = ft_substr(t_buf, 0, i + 1);
	else
	{
		out = ft_substr(t_buf, i + 1, ft_strlen(t_buf) - (i));
		free(t_buf);
	}
	return (out);
}

// char	*ft_check_buf(char *t_buf)
// {
// 	int		i;
// 	char	*out;

// 	i = 0;
// 	while (t_buf[i] != '\n' && t_buf[i] != '\0')
// 		i++;
// 	out = ft_substr(t_buf, 0, i + 1);
// 	return (out);
// }

// char	*ft_edit_buf(char *t_buf)
// {
// 	int		i;
// 	char	*out;

// 	i = 0;
// 	while (t_buf[i] != '\n' && t_buf[i] != '\0')
// 		i++;
// 	out = ft_substr(t_buf, i + 1, ft_strlen(t_buf) - (i + 1));
// 	free(t_buf);
// 	return (out);
// }

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
