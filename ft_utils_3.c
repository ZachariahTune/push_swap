/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:38:03 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:38:04 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_count;

	i = 0;
	dest_count = 0;
	while (dest[dest_count])
	{
		dest_count++;
	}
	while (src[i])
	{
		dest[dest_count] = src[i];
		dest_count++;
		i++;
	}
	dest[dest_count] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	slen;

	slen = ft_strlen(s);
	ret = malloc(sizeof(char) * (slen + 1));
	if (ret == NULL)
	{
		return (NULL);
	}
	ft_memcpy(ret, s, slen);
	ret[slen] = '\0';
	if (slen > 0 && ret[slen - 1] == '\r')
	{
		ret[slen - 1] = '\0';
	}
	return (ret);
}

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if ((dest == src) || n == 0)
	{
		return (dest);
	}
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
