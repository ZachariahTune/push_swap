/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:37:22 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:37:25 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_argv_validation(int argc, char **argv, int ci, int vi)
{
	while (ci < argc)
	{
		if (!ft_contentdigit(argv[ci]))
		{
			ft_puterror(5);
		}
		vi = 0;
		while (argv[ci][vi])
		{
			if (ft_isspace(argv[ci][vi]) ||
				(ft_issign(argv[ci][vi]) && ft_isdigit(argv[ci][vi + 1])) ||
				(ft_isdigit(argv[ci][vi]) && ft_isafterdigit(argv[ci][vi + 1])))
			{
				vi++;
			}
			else
			{
				ft_puterror(6);
			}
		}
		ci++;
	}
}

void	ft_stacks_nullinit(t_stacks *stacks)
{
	stacks->countA = 0;
	stacks->countB = 0;
	stacks->min = 0;
	stacks->med = 0;
	stacks->max = 0;
	stacks->a = NULL;
	stacks->b = NULL;
}

static void	ft_stack_fill(t_stacks *stacks, char **array, int count, int i)
{
	t_stack	*new_element;

	new_element = ft_listlast(stacks->a);
	while (i < count)
	{
		if (stacks->a == NULL)
		{
			new_element = (t_stack *)malloc(sizeof(t_stack));
			if (new_element == NULL)
				ft_puterror(3);
			stacks->a = new_element;
		}
		else
		{
			new_element->next = (t_stack *)malloc(sizeof(t_stack));
			if (new_element->next == NULL)
				ft_puterror(4);
			new_element = new_element->next;
		}
		new_element->next = NULL;
		new_element->steps = 0;
		new_element->trend = 0;
		new_element->value = ft_atoi(array[i], stacks, array, count);
		i++;
	}
}

void	ft_argv_separation(t_stacks *stacks, int argc, char **argv, int ci)
{
	char	**argv_array;
	int		argv_array_count;

	while (ci < argc)
	{
		argv_array_count = ft_split_count(argv[ci], ' ');
		argv_array = ft_split(argv[ci], ' ');
		if (argv_array == NULL)
		{
			ft_puterror(7);
		}
		ft_stack_fill(stacks, argv_array, argv_array_count, 0);
		ft_arrayfree(&argv_array, argv_array_count);
		ci++;
	}
}

void	ft_stackA_characters(t_stacks *stacks)
{
	int	*stackA_array;

	stacks->countA = ft_listsize(stacks->a);
	stacks->min = ft_listmin(stacks->a, 0);
	stacks->max = ft_listmax(stacks->a, 0);
	stacks->med = ft_listmed(stacks->a, stacks->min, stacks->max, 0);
	stackA_array = ft_list_to_array(stacks->a, stacks->countA);
	if (stackA_array == NULL)
		ft_puterror(8);
	if (ft_array_duplicate(stackA_array, stacks->countA))
	{
		ft_stacks_free(&stacks);
		free(stackA_array);
		stackA_array = NULL;
		ft_puterror(9);
	}
	free(stackA_array);
	stackA_array = NULL;
}
