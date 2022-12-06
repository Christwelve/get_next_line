/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:13:35 by cmeng             #+#    #+#             */
/*   Updated: 2022/12/06 09:25:36 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

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
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s) + 1;
	ptr1 = malloc((len + 1) * sizeof(char));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr1;
	size_t		len;
	size_t		i;
	size_t		j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr1 = malloc(len * sizeof(char));
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
	return (ptr1);
}
