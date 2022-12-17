/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:22:09 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/16 18:38:02 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack **list)
{
	int		i;
	int		j;
	int		max;
	t_stack	*node;

	i = 0;
	j = 0;
	node = *list;
	max = node->index;
	node = node->next;
	while (node)
	{
		if (max < node->index)
		{
			max = node->index;
			node = node->next;
			j = ++i;
		}
		else
		{
			node = node->next;
			i++;
		}
	}
	return (j);
}

int	issorted_detals(t_stack **list_a, t_stack **list_b, t_data *data)
{
	if (check_issorted(list_a) == 1)
	{
		index_1(list_a);
		index_list(list_a, data->len);
		data->list_len = ft_listlen(*list_a);
		sort_list(list_a, list_b, data->list_len);
	}
	return (0);
}
