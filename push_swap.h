/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:13:49 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/16 18:39:29 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				data;
	int				index;
}				t_stack;

typedef struct s_data
{
	unsigned int	list_len;
	int				i;
	char			*joined_str;
	char			**splited_str;
	int				len;
}				t_data;

void			check_char(char **str);
void			check_valid(char **str);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *s);
int				find_max(t_stack **list);
char			**ft_split(char const *s, char c);
long int		ft_atoi(const char *str);
t_stack			*append(t_stack **head, int new_data);
void			fill_list(t_stack **list, char **num, int *len);
int				check_dublicates(t_stack **head);
int				check_issorted(t_stack **list);
void			ft_printerror(void);
int				sa(t_stack **list);
int				sb(t_stack **list);
int				ss(t_stack **list_a, t_stack **list_b);
int				pa(t_stack **list_a, t_stack **list_b);
int				pb(t_stack **list_b, t_stack **list_a);
int				ra(t_stack **list_a);
int				rb(t_stack **list_b);
int				rr(t_stack **list_a, t_stack **list_b);
int				rra(t_stack **list_a);
int				rrb(t_stack **list_b);
int				rrr(t_stack **list_a, t_stack **list_b);
void			index_list(t_stack **list, int len);
void			index_1(t_stack **list);
void			sort_2(t_stack **list_a);
void			sort_3(t_stack **list_a);
void			sort_4(t_stack **list_a, t_stack **list_b);
void			sort_5(t_stack **list_a, t_stack **list_b);
unsigned int	ft_listlen(t_stack *list);
void			sort_list(t_stack **list_a, t_stack **list_b, int len);
void			butterfly_sort(t_stack **list_a, t_stack **list_b, int n);
void			push_list_a(t_stack **list_a, t_stack **list_b, int len);
int				issorted_detals(t_stack **list_a,
					t_stack **list_b, t_data *data);
void			free_all(t_data **data, t_stack **list_a, t_stack **list_b);
#endif
