/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:38:19 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:38:20 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listmax(t_stack *list, int limit)
{
	int	max;
	int	limit_count;

	max = list->value;
	limit_count = 0;
	while (list && (limit == 0 || limit_count < limit))
	{
		if (list->value > max)
			max = list->value;
		list = list->next;
		limit_count++;
	}
	return (max);
}

int	ft_listmed(t_stack *list, int min, int max, int limit)
{
	t_stack	*new_list;
	int		new_min;
	int		new_max;
	int		limit_count;

	new_list = list;
	new_min = max;
	new_max = min;
	limit_count = 0;
	while (new_list && (limit == 0 || limit_count < limit))
	{
		if (new_list->value < new_min && new_list->value > min)
			new_min = new_list->value;
		if (new_list->value > new_max && new_list->value < max)
			new_max = new_list->value;
		new_list = new_list->next;
		limit_count++;
	}
	if (new_min >= new_max)
		return (new_min);
	else
		return (ft_listmed(list, new_min, new_max, limit));
}

int	*ft_list_to_array(t_stack *list, int count)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * count);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		array[i] = list->value;
		list = list->next;
		i++;
	}
	return (array);
}

void	ft_arrayfree(char ***array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

int	ft_array_duplicate(int *array, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < (count - 1))
	{
		j = i + 1;
		while (j < count)
		{
			if (array[i] == array[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
