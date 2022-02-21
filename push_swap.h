/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztune <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:33:53 by ztune             #+#    #+#             */
/*   Updated: 2021/08/20 13:33:55 by ztune            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# define MAXINT 2147483647
# define MININT -2147483648
# define GNL_BUFF_SIZE 32

typedef struct s_steps
{
	int				stepsA;
	int				trendA;
	int				stepsB;
	int				trendB;
}	t_steps;

typedef struct s_stack
{
	int				value;
	int				steps;
	int				trend;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int				countA;
	int				countB;
	int				min;
	int				med;
	int				max;
	t_stack			*a;
	t_stack			*b;
}	t_stacks;

//Работа со стеками
void	ft_argv_validation(int argc, char **argv, int ci, int vi);
void	ft_stacks_nullinit(t_stacks *stacks);
void	ft_argv_separation(t_stacks *stack_a, int argc, char **argv, int ci);
void	ft_stackA_characters(t_stacks *stacks);
int		ft_stack_sorted(t_stack *list);
void	ft_stack_sort(t_stacks *stacks);
void	ft_stacks_free(t_stacks **stacks);
//Глобальная сортировка стека А
void	ft_sort_more5(t_stacks *stacks);
void	ft_save_new_steps(t_steps *steps, int stepsA, int trendA, t_stack *tB);
int		ft_min_element_trend(t_stack *stack, int min);
//Инструкции для стеков
void	ft_rule_sa(t_stacks *stacks, int write);
void	ft_rule_sb(t_stacks *stacks, int write);
void	ft_rule_ss(t_stacks *stacks, int write);
void	ft_rule_pa(t_stacks *stacks, int write);
void	ft_rule_pb(t_stacks *stacks, int write);
void	ft_rule_ra(t_stacks *stacks, int write);
void	ft_rule_rb(t_stacks *stacks, int write);
void	ft_rule_rr(t_stacks *stacks, int write);
void	ft_rule_rra(t_stacks *stacks, int write);
void	ft_rule_rrb(t_stacks *stacks, int write);
void	ft_rule_rrr(t_stacks *stacks, int write);
//Комбинации инструкций
void	ft_rule_rra_pb(t_stacks *stacks, int write);
void	ft_rule_rra_pb_rra_pb(t_stacks *stacks, int write);
void	ft_rule_rra_rra_pb_pb(t_stacks *stacks, int write);
//Объединение инструкций
char	*ft_rules_replace_rr(char *s, char *r, int i, int j);
char	*ft_rules_replace_rrr(char *s, char *r, int i, int j);
//Функции Get_Next_Line
int		get_next_line(int fd, char **line, char **after);
int		gnl_strchr_length(char *s, int c);
char	*gnl_strjoin(char **s1, const char *s2, int *before);
//Общие вспомогательные функции
void	ft_putchar(int c, int stderr);
void	ft_putstr(char *str);
void	ft_putrule(char *str, int finish);
void	ft_puterror(int code);
void	ft_puterror_atoi(t_stacks *stacks, char **array, int count, int code);
int		ft_isspace(int c);
int		ft_issign(int c);
int		ft_isdigit(int c);
int		ft_contentdigit(char *str);
int		ft_isafterdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup(const char *s);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *str, t_stacks *stacks, char **array, int count);
t_stack	*ft_listlast(t_stack *list);
t_stack	*ft_listprelast(t_stack *list);
int		ft_listsize(t_stack *list);
int		ft_listmin(t_stack *list, int limit);
int		ft_listmax(t_stack *list, int limit);
int		ft_listmed(t_stack *list, int min, int max, int limit);
int		*ft_list_to_array(t_stack *list, int count);
void	ft_arrayfree(char ***array, size_t count);
int		ft_array_duplicate(int *array, int count);
int		ft_split_count(char const *str, char c);
char	**ft_split(char const *s, char c);

#endif
