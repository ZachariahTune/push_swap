/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:37:52 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:37:53 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar(int c, int stderr)
{
	if (stderr == 0)
		write(1, &c, 1);
	if (stderr == 1)
		write(2, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	int	stderr;

	stderr = 0;
	if (str[0] == 'E' && str[1] == 'r' && str[2] == 'r'
		&& str[3] == 'o' && str[4] == 'r' && str[5] == '\n')
		stderr = 1;
	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], stderr);
		i++;
	}
}

void	ft_putrule(char *str, int finish)
{
	static char	rules_str[1000000];

	ft_strcat(rules_str, str);
	if (finish == 1)
	{
		ft_rules_replace_rr(rules_str, "\nra\nrb", 0, 0);
		ft_rules_replace_rr(rules_str, "\nrb\nra", 0, 0);
		ft_rules_replace_rrr(rules_str, "\nrra\nrrb", 0, 0);
		ft_rules_replace_rrr(rules_str, "\nrrb\nrra", 0, 0);
		ft_putstr(rules_str);
	}
}

void	ft_puterror(int code)
{
	if (code > 1)
		ft_putstr("Error\n");
	exit(1);
}

/*
void	ft_puterror(int code)
{
	ft_putstr("Error: ");
	if(code == 1)
		ft_putstr("Ni odin argument ne byl peredan\n");
	if(code == 2)
		ft_putstr("Ne udalos videlit pamyat pod steki\n");
	if(code == 3)
		ft_putstr("Ne udalos videlit pamyat pod perviy element stekа A\n");
	if(code == 4)
		ft_putstr("Ne udalos videlit pamyat pod sleduyushiy element stekа A\n");
	if(code == 5)
		ft_putstr("Odin iz argumentov ne soderzhit chisla\n");
	if(code == 6)
		ft_putstr("Stroka argumentov soderzhit nekorrektniy simvol\n");
	if(code == 7)
		ft_putstr("Ne udalos videlit pamyat pri vipolnenii funkcii SPLIT\n");
	if(code == 8)
		ft_putstr("Ne udalos videlit pamyat pri perevode steka A v massiv\n");
	if(code == 9)
		ft_putstr("V steke A obnaruzhen dublicat\n");
	if(code == 10)
		ft_putstr("Stroka argumentov soderzhit slishkom dlinnoe chislo\n");
	if(code == 11)
		ft_putstr("Ne udalos videlit pamyat pod strukturu STEPS\n");
	if(code == 12)
		ft_putstr("\n");
	if(code == 13)
		ft_putstr("Stroka otveta ne sootvetstvuet ni odnoy instrukcii\n");
	if(code == 100)
		ft_putstr("Prinuditelnaya ostanovka\n");
	exit(1);
}
*/

void	ft_puterror_atoi(t_stacks *stacks, char **array, int count, int code)
{
	ft_arrayfree(&array, count);
	ft_stacks_free(&stacks);
	ft_puterror(code);
}
