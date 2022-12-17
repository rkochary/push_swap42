/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:40:00 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/15 14:11:29 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **list_a)
{
	t_stack	*a;
	t_stack	*tmp;

	a = *list_a;
	tmp = a;
	if (!a || !a->next)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	while (a->next != tmp)
		a = a->next;
	a->next = NULL;
	tmp->next = *list_a;
	*list_a = tmp;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack **list_b)
{
	t_stack	*b;
	t_stack	*tmp;

	b = *list_b;
	tmp = b;
	if (!b || !b->next)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	while (b->next != tmp)
		b = b->next;
	b->next = NULL;
	tmp->next = *list_b;
	write(1, "rrb\n", 4);
	*list_b = tmp;
	return (0);
}

int	rrr(t_stack **list_a, t_stack **list_b)
{
	rra(list_a);
	rrb(list_b);
	write(1, "rrr\n", 4);
	return (0);
}
