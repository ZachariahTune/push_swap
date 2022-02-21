/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:36:09 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:36:10 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rule_ra(t_stacks *stacks, int write)
{
	t_stack	*first_list;
	t_stack	*second_list;
	t_stack	*last_list;

	if (stacks->countA < 2)
		return ;
	first_list = stacks->a;
	second_list = stacks->a->next;
	last_list = ft_listlast(stacks->a);
	first_list->next = NULL;
	last_list->next = first_list;
	stacks->a = second_list;
	if (write == 1)
	{
		ft_putrule("ra\n", 0);
	}
}

void	ft_rule_rb(t_stacks *stacks, int write)
{
	t_stack	*first_list;
	t_stack	*second_list;
	t_stack	*last_list;

	if (stacks->countB < 2)
		return ;
	first_list = stacks->b;
	second_list = stacks->b->next;
	last_list = ft_listlast(stacks->b);
	first_list->next = NULL;
	last_list->next = first_list;
	stacks->b = second_list;
	if (write == 1)
	{
		ft_putrule("rb\n", 0);
	}
}

void	ft_rule_rr(t_stacks *stacks, int write)
{
	ft_rule_ra(stacks, 0);
	ft_rule_rb(stacks, 0);
	if (write == 1)
	{
		ft_putrule("rr\n", 0);
	}
}

void	ft_rule_rra(t_stacks *stacks, int write)
{
	t_stack	*first_list;
	t_stack	*prelast_list;
	t_stack	*last_list;

	if (stacks->countA < 2)
		return ;
	first_list = stacks->a;
	prelast_list = ft_listprelast(stacks->a);
	last_list = prelast_list->next;
	prelast_list->next = NULL;
	last_list->next = first_list;
	stacks->a = last_list;
	if (write == 1)
	{
		ft_putrule("rra\n", 0);
	}
}

void	ft_rule_rrb(t_stacks *stacks, int write)
{
	t_stack	*first_list;
	t_stack	*prelast_list;
	t_stack	*last_list;

	if (stacks->countB < 2)
		return ;
	first_list = stacks->b;
	prelast_list = ft_listprelast(stacks->b);
	last_list = prelast_list->next;
	prelast_list->next = NULL;
	last_list->next = first_list;
	stacks->b = last_list;
	if (write == 1)
	{
		ft_putrule("rrb\n", 0);
	}
}
