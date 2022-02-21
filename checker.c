/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:34:40 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:34:58 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	int		dif;

	i = 0;
	while (((const unsigned char *)s1)[i]
		|| ((const unsigned char *)s2)[i])
	{
		dif = ((const unsigned char *)s1)[i]
			- ((const unsigned char *)s2)[i];
		if (dif != 0)
		{
			return (dif);
		}
		i++;
	}
	return (0);
}

static int	ft_rule_processing(char *line, t_stacks *stacks)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_rule_sa(stacks, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_rule_sb(stacks, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ft_rule_ss(stacks, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_rule_pa(stacks, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_rule_pb(stacks, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_rule_ra(stacks, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rule_rb(stacks, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rule_rr(stacks, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rule_rra(stacks, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rule_rrb(stacks, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rule_rrr(stacks, 0);
	else
		return (0);
	return (1);
}

static void	ft_read_rules(t_stacks *stacks, char *gnl_line, char *gnl_after)
{
	while (get_next_line(0, &gnl_line, &gnl_after))
	{
		if (ft_rule_processing(gnl_line, stacks) == 0)
		{
			free(gnl_line);
			gnl_line = NULL;
			free(gnl_after);
			gnl_after = NULL;
			ft_stacks_free(&stacks);
			ft_puterror(13);
		}
		free(gnl_line);
		gnl_line = NULL;
	}
	if (gnl_line[0] != '\0' && gnl_after == NULL)
	{
		free(gnl_line);
		gnl_line = NULL;
		ft_stacks_free(&stacks);
		ft_puterror(13);
	}
	free(gnl_line);
	gnl_line = NULL;
}

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
	ft_read_rules(stacks, NULL, NULL);
	if (ft_stack_sorted(stacks->a) && stacks->countB == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_stacks_free(&stacks);
	return (0);
}
