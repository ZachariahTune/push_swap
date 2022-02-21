/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:36:51 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:36:53 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_save_new_steps(t_steps *steps, int stepsA, int trendA, t_stack *tB)
{
	steps->stepsA = stepsA;
	steps->trendA = trendA;
	steps->stepsB = tB->steps;
	steps->trendB = tB->trend;
}

int	ft_min_element_trend(t_stack *stack, int min)
{
	while (stack)
	{
		if (stack->value == min)
			return (stack->trend);
		stack = stack->next;
	}
	return (1);
}
