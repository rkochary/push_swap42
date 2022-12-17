/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:17:37 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/15 16:09:42 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_sort(t_stack **list_a, t_stack **list_b, int n)
{
	int	count;

	count = 0;
	while ((*list_a))
	{
		if ((*list_a)->index <= count)
		{
			pb(list_a, list_b);
			rb(list_b);
			count++;
		}
		else if ((*list_a)->index <= count + n)
		{
			pb(list_a, list_b);
			count++;
		}
		else
		{
			ra(list_a);
		}
	}
}

void	push_list_a(t_stack **list_a, t_stack **list_b, int len)
{
	int	max;

	max = 0;
	while (*list_b)
	{
	max = find_max(list_b);
		if (max <= len / 2)
		{
			while (max-- >= 1)
				rb(list_b);
			pa(list_a, list_b);
			len--;
		}
		else
		{
			while (len - max)
			{
				rrb(list_b);
				max++;
			}
			pa(list_a, list_b);
			len--;
		}
	}
}
