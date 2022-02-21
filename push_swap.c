/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:34:13 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:34:15 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	ft_argv_validation(argc, argv, 1, 0);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_puterror(2);
	ft_stacks_nullinit(stacks);
	ft_argv_separation(stacks, argc, argv, 1);
	ft_stackA_characters(stacks);
	if (!ft_stack_sorted(stacks->a))
		ft_stack_sort(stacks);
	ft_stacks_free(&stacks);
	ft_putrule("", 1);
	return (0);
}
