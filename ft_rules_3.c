/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:36:17 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:36:19 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rule_rrr(t_stacks *stacks, int write)
{
	ft_rule_rra(stacks, 0);
	ft_rule_rrb(stacks, 0);
	if (write == 1)
	{
		ft_putrule("rrr\n", 0);
	}
}

void	ft_rule_rra_pb(t_stacks *stacks, int write)
{
	ft_rule_rra(stacks, write);
	ft_rule_pb(stacks, write);
}

void	ft_rule_rra_pb_rra_pb(t_stacks *stacks, int write)
{
	ft_rule_rra_pb(stacks, write);
	ft_rule_rra_pb(stacks, write);
}

void	ft_rule_rra_rra_pb_pb(t_stacks *stacks, int write)
{
	ft_rule_rra(stacks, write);
	ft_rule_rra_pb(stacks, write);
	ft_rule_pb(stacks, write);
}
