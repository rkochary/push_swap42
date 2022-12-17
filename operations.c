/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:00:08 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/15 16:04:42 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack **list_a)
{
	t_stack	*tmp;
	t_stack	*a;

	if (*list_a)
	{
		a = *list_a;
		tmp = a->next;
		a->next = tmp->next;
		tmp->next = a;
		a = tmp;
		*list_a = a;
		write(1, "sa\n", 3);
	}
	return (0);
}

int	sb(t_stack **list_b)
{
	t_stack	*tmp;
	t_stack	*b;

	if (*list_b)
	{
		b = *list_b;
		tmp = b->next;
		b->next = tmp->next;
		tmp->next = b;
		b = tmp;
		*list_b = b;
		write(1, "sb\n", 3);
	}
	return (0);
}

int	ss(t_stack **list_a, t_stack **list_b)
{
	sa(list_a);
	sb(list_b);
	write (1, "ss\n", 3);
	return (0);
}

int	pa(t_stack **list_a, t_stack **list_b)
{
	t_stack	*b;

	b = *list_b;
	if (*list_b)
		(*list_b) = (*list_b)->next;
	else
		return (0);
	b->next = (*list_a);
	(*list_a) = b;
	write (1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **list_a, t_stack **list_b)
{
	t_stack	*a;

	a = *list_a;
	if (*list_a)
	{
		(*list_a) = (*list_a)->next;
		a->next = (*list_b);
		(*list_b) = a;
		write (1, "pb\n", 3);
	}
	return (0);
}
