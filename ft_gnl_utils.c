/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:35:32 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:35:33 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	gnl_strchr_length(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	if ((char)c == '\0')
		return (i);
	return (-1);
}

char	*gnl_strjoin(char **s1, const char *s2, int *before)
{
	char	*ret;
	size_t	slen[2];

	if (*s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	if (*s1 != NULL && s2 == NULL)
		return (ft_strdup(*s1));
	if (*s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	slen[0] = ft_strlen(*s1);
	slen[1] = ft_strlen(s2);
	ret = malloc(sizeof(char) * (slen[0] + slen[1] + 1));
	if (ret == NULL)
	{
		*before = -2;
		free(*s1);
		*s1 = NULL;
		return (NULL);
	}
	ft_memcpy(ret, *s1, slen[0]);
	ft_memcpy(ret + slen[0], s2, slen[1]);
	ret[slen[0] + slen[1]] = '\0';
	free(*s1);
	*s1 = NULL;
	return (ret);
}
