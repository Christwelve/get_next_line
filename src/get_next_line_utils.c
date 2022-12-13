/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:35 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/13 05:06:45 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

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

char	*ft_strjoin(char *s1, char *s2)
{
	char		*ptr1;
	size_t		len;
	size_t		i;
	size_t		j;

	if (s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr1 = ft_calloc(len, sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i < ft_strlen(s1))
			ptr1[i] = s1[i];
		else
			ptr1[i] = s2[j++];
		i++;
	}
	ptr1[i] = 0;
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

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*ptr1;
	int			len;

	len = ft_strlen(s1);
	ptr1 = ft_calloc((len + 1), sizeof(char));
	if (ptr1 == NULL)
	{
		return (NULL);
	}
	ft_strlcpy (ptr1, s1, len + 1);
	return (ptr1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char		*ptr_src;
	char			*ptr_dst;
	unsigned int	i;

	ptr_src = src;
	ptr_dst = dst;
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((i < dstsize - 1) && (ptr_src[i] != '\0'))
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	ptr_dst[i] = '\0';
	return (ft_strlen(src));
}