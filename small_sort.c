/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:48:14 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/15 15:14:23 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **list_a)
{
	if ((*list_a)->next && (*list_a)->data > (*list_a)->next->data)
		sa(list_a);
}

void	sort_3(t_stack **list_a)
{
	int	i;

	i = find_max(list_a);
	if (i == 2)
		sort_2(list_a);
	if (i == 1)
	{
		rra(list_a);
		sort_2(list_a);
	}
	if (i == 0)
	{
		ra(list_a);
		sort_2(list_a);
	}
}

void	sort_4(t_stack **list_a, t_stack **list_b)
{
	int	i;

	i = find_max(list_a);
	if (i == 3)
		rra(list_a);
	else if (i == 2)
	{
		rra(list_a);
		rra(list_a);
	}
	else if (i == 1)
		ra(list_a);
	pb(list_a, list_b);
	sort_3(list_a);
	pa(list_a, list_b);
	ra(list_a);
}

void	sort_5(t_stack **list_a, t_stack **list_b)
{
	int	i;

	i = find_max(list_a);
	if (i == 4)
		rra(list_a);
	else if (i == 3)
	{
		rra(list_a);
		rra(list_a);
	}
	else if (i == 2)
	{
		ra(list_a);
		ra(list_a);
	}
	else if (i == 1)
		ra(list_a);
	pb(list_a, list_b);
	sort_4(list_a, list_b);
	pa(list_a, list_b);
	ra(list_a);
}

void	sort_list(t_stack **list_a, t_stack **list_b, int len)
{
	if (len == 2)
		sort_2(list_a);
	else if (len == 3)
		sort_3(list_a);
	else if (len == 4)
		sort_4(list_a, list_b);
	else if (len == 5)
		sort_5(list_a, list_b);
	else if (len >= 6 && len <= 100)
	{
		butterfly_sort(list_a, list_b, 15);
		push_list_a(list_a, list_b, len);
	}
	else if (len > 100 && len < 500)
	{
		butterfly_sort(list_a, list_b, 30);
		push_list_a(list_a, list_b, len);
	}
	else if (len >= 500)
	{
		butterfly_sort(list_a, list_b, 40);
		push_list_a(list_a, list_b, len);
	}
}
