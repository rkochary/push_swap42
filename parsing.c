/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:31:15 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/26 12:57:44 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	ft_printerror(void)
{
	write (2, "Error\n", 6);
	exit(0);
}

void	check_char(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (((str[i][j] >= '0' && str[i][j] <= '9') || \
			((str[i][j] == '+' || str[i][j] == '-') && \
			((str[i][j + 1] >= '0' && str[i][j + 1] <= '9') && j == 0))))
			{
				j++ ;
			}
			else
				ft_printerror();
		}
		i++;
	}
}

void	check_valid(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] == '+' || str[i][j] == '-')
						&& j != 0)
				ft_printerror();
			j++;
		}
		i++;
	}
}

int	check_dublicates(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*ptr;

	tmp = *head;
	while (*head)
	{
		ptr = (*head)->next;
		while (ptr)
		{
			if (ptr->data == (*head)->data)
				ft_printerror();
			ptr = ptr->next;
		}
		ptr = (*head)->next;
		*head = ptr;
	}
	*head = tmp;
	return (0);
}

int	check_issorted(t_stack **list)
{
	int		num;
	t_stack	*tmp;
	t_stack	*tmp_num;

	tmp = *list;
	while (*list)
	{
		num = (*list)->data;
		tmp_num = (*list)->next;
		*list = tmp_num;
		while (*list)
		{
			if (num > (*list)->data)
			{
				*list = tmp;
				return (1);
			}
			*list = (*list)->next;
		}
		*list = tmp_num;
	}
	*list = tmp;
	return (0);
}
