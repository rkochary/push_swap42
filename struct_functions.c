/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:12:45 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/23 12:53:49 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*append(t_stack **head, int new_data)
{
	t_stack	*tmp;
	t_stack	*new_node;
	t_stack	*last_node;

	last_node = 0;
	new_node = malloc(sizeof(t_stack));
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	else
	{
		last_node = *head;
		tmp = last_node;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		last_node->next->next = 0;
		last_node = tmp;
	}
	return (last_node);
}

void	index_1(t_stack **list)
{
	t_stack	*temp;

	temp = *list;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

void	fill_list(t_stack **list, char **num, int *len)
{
	int		i;
	int		n;
	t_stack	*node;

	i = 0;
	node = 0;
	while (num[i])
	{
		n = ft_atoi(num[i]);
		node = append(&node, n);
		i++;
	}
	(*len) = i;
	*list = node;
}

void	index_list(t_stack **list, int len)
{
	t_stack	*node;
	t_stack	*max;
	int		i;

	i = 0;
	node = (*list)->next;
	max = *list;
	index_1(list);
	while (i < len)
	{
		while (node != NULL)
		{
			if (max->data > node->data && node->index == -1)
				max = node;
			node = node->next;
		}
		max->index = i;
		max = *list;
		node = *list;
		i++;
		while (i < len && max->index != -1 && max->next != NULL)
		{
			max = max->next;
		}
	}
}
