/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:38:12 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:38:13 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_stacks *stacks, char **array, int count)
{
	int			sign;
	int			num_count;
	long int	ret;

	sign = 1;
	num_count = 0;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num_count++;
		ret = ret * 10 + (*str - 48);
		if (num_count > 10 || (ret * sign) > MAXINT || (ret * sign) < MININT)
			ft_puterror_atoi(stacks, array, count, 10);
		str++;
	}
	return ((int)(ret * sign));
}

t_stack	*ft_listlast(t_stack *list)
{
	if (list == NULL)
	{
		return (NULL);
	}
	while (list)
	{
		if (list->next == NULL)
		{
			return (list);
		}
		list = list->next;
	}
	return (list);
}

t_stack	*ft_listprelast(t_stack *list)
{
	if (list == NULL)
	{
		return (NULL);
	}
	while (list)
	{
		if (list->next->next == NULL)
		{
			return (list);
		}
		list = list->next;
	}
	return (list);
}

int	ft_listsize(t_stack *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	ft_listmin(t_stack *list, int limit)
{
	int	min;
	int	limit_count;

	min = list->value;
	limit_count = 0;
	while (list && (limit == 0 || limit_count < limit))
	{
		if (list->value < min)
			min = list->value;
		list = list->next;
		limit_count++;
	}
	return (min);
}
