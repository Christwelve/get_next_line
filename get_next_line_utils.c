/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:35 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/19 13:28:49 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int in_len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr1;
	int				i;

	if (s == NULL)
		return (NULL);
	if (len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) + 1;
	ptr1 = ft_calloc((len + 1), sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	i = 0;
	while (i < (int) len && s[start + i] != '\0')
	{
		ptr1[i] = s[start + i];
		i++;
	}
	ptr1[i] = 0;
	return (ptr1);
}

char	*ft_strjoin(char *s1, char *s2, int in_len)
{
	char		*ptr1;
	size_t		len;
	size_t		i;
	size_t		j;

	if (s2 == NULL)
		return (0);
	len = ft_strlen(s1) + in_len;
	ptr1 = ft_calloc(len + 1, sizeof(char));
	if (ptr1 == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < (len - in_len))
			ptr1[i] = s1[i];
		else
			ptr1[i] = s2[j++];
		i++;
	}
	ptr1[len] = 0;
	free(s1);
	return (ptr1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	if (count != 0)
	{
		if ((count * size) / count != size)
			return (NULL);
	}
	ptr = malloc (count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr1;

	ptr1 = (char *) s;
	while (n > 0)
	{
		*ptr1++ = '\0';
		n--;
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
