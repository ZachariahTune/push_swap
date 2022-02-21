/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:36:26 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:36:27 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_rules_replace_rr(char *s, char *r, int i, int j)
{
	while (s[i])
	{
		if (s[i] == r[0] && s[i + 1] == r[1] && s[i + 2] == r[2]
			&& s[i + 3] == r[3] && s[i + 4] == r[4] && s[i + 5] == r[5])
		{
			s[i + 1] = 'r';
			s[i + 2] = 'r';
			j = i + 3;
			while (s[j + 2] != '\0')
			{
				s[j] = s[j + 3];
				j++;
			}
		}
		i++;
		if (s[i] == '\0' && j > 0)
		{
			i = 0;
			j = 0;
		}
	}
	return (s);
}

char	*ft_rules_replace_rrr(char *s, char *r, int i, int j)
{
	while (s[i])
	{
		if (s[i] == r[0] && s[i + 1] == r[1] && s[i + 2] == r[2]
			&& s[i + 3] == r[3] && s[i + 4] == r[4] && s[i + 5] == r[5]
			&& s[i + 6] == r[6] && s[i + 7] == r[7])
		{
			s[i + 1] = 'r';
			s[i + 2] = 'r';
			s[i + 3] = 'r';
			j = i + 4;
			while (s[j + 3] != '\0')
			{
				s[j] = s[j + 4];
				j++;
			}
		}
		i++;
		if (s[i] == '\0' && j > 0)
		{
			i = 0;
			j = 0;
		}
	}
	return (s);
}
