/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:36:42 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:36:43 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_steps_mark(t_stack *stack, int count, int i)
{
	int		half;

	half = count / 2;
	while (i <= half)
	{
		stack->steps = i;
		stack->trend = 1;
		stack = stack->next;
		i++;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		stack->steps = i;
		stack->trend = -1;
		stack = stack->next;
	}
}

static void	ft_search_min_steps(t_stacks *stacks, t_steps *steps)
{
	int		stepsA;
	int		trendA;
	t_stack	*tmpA;
	t_stack	*tmpB;

	tmpB = stacks->b;
	while (tmpB)
	{
		stepsA = 0;
		trendA = 1;
		tmpA = stacks->a;
		while (tmpA->next)
		{
			if (tmpB->value > tmpA->value && tmpB->value < tmpA->next->value)
			{
				stepsA = tmpA->next->steps;
				trendA = tmpA->next->trend;
			}
			tmpA = tmpA->next;
		}
		if ((tmpB->steps + stepsA) < (steps->stepsA + steps->stepsB))
			ft_save_new_steps(steps, stepsA, trendA, tmpB);
		tmpB = tmpB->next;
	}
}

static void	ft_rules_exec(t_stacks *stacks, t_steps *steps)
{
	while (steps->stepsA > 0)
	{
		if (steps->trendA == 1)
			ft_rule_ra(stacks, 1);
		else
			ft_rule_rra(stacks, 1);
		steps->stepsA--;
	}
	while (steps->stepsB > 0)
	{
		if (steps->trendB == 1)
			ft_rule_rb(stacks, 1);
		else
			ft_rule_rrb(stacks, 1);
		steps->stepsB--;
	}
	ft_rule_pa(stacks, 1);
}

static void	ft_sort_more5_BtoA(t_stacks *stacks)
{
	t_steps	*steps;

	steps = (t_steps *)malloc(sizeof(t_steps));
	if (steps == NULL)
		ft_puterror(11);
	while (stacks->countB != 0)
	{
		ft_stack_steps_mark(stacks->a, stacks->countA, 0);
		ft_stack_steps_mark(stacks->b, stacks->countB, 0);
		steps->stepsA = 1000000;
		steps->stepsB = 1000000;
		ft_search_min_steps(stacks, steps);
		ft_rules_exec(stacks, steps);
	}
	ft_stack_steps_mark(stacks->a, stacks->countA, 0);
	if (ft_min_element_trend(stacks->a, stacks->min) == 1)
	{
		while (stacks->a->value != stacks->min)
			ft_rule_ra(stacks, 1);
	}
	else
		while (stacks->a->value != stacks->min)
			ft_rule_rra(stacks, 1);
	free(steps);
}

void	ft_sort_more5(t_stacks *stacks)
{
	while (stacks->countA > 2)
	{
		if (stacks->a->value != stacks->min && stacks->a->value != stacks->max)
		{
			ft_rule_pb(stacks, 1);
			if (stacks->b->value >= stacks->med)
				ft_rule_rb(stacks, 1);
		}
		else
			ft_rule_ra(stacks, 1);
	}
	if (stacks->a->value < stacks->a->next->value)
		ft_rule_ra(stacks, 1);
	ft_rule_pa(stacks, 1);
	ft_sort_more5_BtoA(stacks);
}
