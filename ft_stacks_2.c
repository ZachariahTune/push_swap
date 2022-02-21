/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:37:32 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:37:34 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_sorted(t_stack *list)
{
	while (list)
	{
		if ((list->next != NULL) && (list->value > list->next->value))
		{
			return (0);
		}
		list = list->next;
	}
	return (1);
}

static void	ft_sort_before3(t_stacks *stacks)
{
	if ((stacks->countA == 2) && (stacks->a->value > stacks->a->next->value))
		ft_rule_sa(stacks, 1);
	else if (stacks->countA == 3)
	{
		if (stacks->a->value == stacks->max)
			ft_rule_ra(stacks, 1);
		if (stacks->a->next->value == stacks->max)
			ft_rule_rra(stacks, 1);
		if (stacks->a->value > stacks->a->next->value)
			ft_rule_sa(stacks, 1);
	}
}

static void	ft_sort_before5(t_stacks *stacks)
{
	if (ft_listlast(stacks->a)->value < stacks->med
		&& ft_listprelast(stacks->a)->value < stacks->med)
	{
		if (ft_listlast(stacks->a)->value == stacks->min)
			ft_rule_rra_pb_rra_pb(stacks, 1);
		else
			ft_rule_rra_rra_pb_pb(stacks, 1);
	}
	else if (ft_listlast(stacks->a)->value == stacks->min)
		ft_rule_rra_pb(stacks, 1);
	while (stacks->countB < 2)
	{
		if (stacks->a->value < stacks->med)
			ft_rule_pb(stacks, 1);
		else
			ft_rule_ra(stacks, 1);
	}
	ft_sort_before3(stacks);
	if (stacks->b->value < stacks->b->next->value)
		ft_rule_sb(stacks, 1);
	ft_rule_pa(stacks, 1);
	ft_rule_pa(stacks, 1);
}

void	ft_stack_sort(t_stacks *stacks)
{
	if (stacks->countA <= 3)
		ft_sort_before3(stacks);
	else if (stacks->countA <= 5)
		ft_sort_before5(stacks);
	else
		ft_sort_more5(stacks);
}

void	ft_stacks_free(t_stacks **stacks)
{
	t_stack	*buf;

	while ((*stacks)->a)
	{
		buf = (*stacks)->a;
		(*stacks)->a = (*stacks)->a->next;
		free(buf);
		buf = NULL;
	}
	while ((*stacks)->b)
	{
		buf = (*stacks)->b;
		(*stacks)->b = (*stacks)->b->next;
		free(buf);
		buf = NULL;
	}
	free(*stacks);
	*stacks = NULL;
}
