/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:36:01 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:36:04 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rule_sa(t_stacks *stacks, int write)
{
	int		buf;

	if (stacks->countA < 2)
		return ;
	buf = stacks->a->value;
	stacks->a->value = stacks->a->next->value;
	stacks->a->next->value = buf;
	if (write == 1)
	{
		ft_putrule("sa\n", 0);
	}
}

void	ft_rule_sb(t_stacks *stacks, int write)
{
	int		buf;

	if (stacks->countB < 2)
		return ;
	buf = stacks->b->value;
	stacks->b->value = stacks->b->next->value;
	stacks->b->next->value = buf;
	if (write == 1)
	{
		ft_putrule("sb\n", 0);
	}
}

void	ft_rule_ss(t_stacks *stacks, int write)
{
	ft_rule_sa(stacks, 0);
	ft_rule_sb(stacks, 0);
	if (write == 1)
	{
		ft_putrule("ss\n", 0);
	}
}

void	ft_rule_pa(t_stacks *stacks, int write)
{
	t_stack	*buf;

	if (stacks->countB == 0)
		return ;
	buf = stacks->b;
	stacks->b = stacks->b->next;
	buf->next = stacks->a;
	stacks->a = buf;
	stacks->countA += 1;
	stacks->countB -= 1;
	if (write == 1)
	{
		ft_putrule("pa\n", 0);
	}
}

void	ft_rule_pb(t_stacks *stacks, int write)
{
	t_stack	*buf;

	if (stacks->countA == 0)
		return ;
	buf = stacks->a;
	stacks->a = stacks->a->next;
	buf->next = stacks->b;
	stacks->b = buf;
	stacks->countB += 1;
	stacks->countA -= 1;
	if (write == 1)
	{
		ft_putrule("pb\n", 0);
	}
}
