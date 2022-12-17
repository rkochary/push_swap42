/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:06:19 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/15 14:10:11 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **list_a)
{
	t_stack	*a;
	t_stack	*tmp;
	t_stack	*ptr;

	a = *list_a;
	if (!a || !a->next)
		return (0);
	tmp = a->next;
	ptr = tmp;
	a->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = a;
	*list_a = ptr;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack **list_b)
{
	t_stack	*b;
	t_stack	*tmp;
	t_stack	*ptr;

	b = *list_b;
	if (!b || !b->next)
		return (0);
	tmp = b->next;
	ptr = tmp;
	b->next = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = b;
	*list_b = ptr;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack **list_a, t_stack **list_b)
{
	ra(list_a);
	rb(list_b);
	write(1, "rr\n", 3);
	return (0);
}
