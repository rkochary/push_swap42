/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochary <rkochary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:24:48 by rkochary          #+#    #+#             */
/*   Updated: 2022/11/26 13:00:44 by rkochary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data **data)
{
	int		i;

	i = -1;
	while ((*data)->splited_str && (*data)->splited_str[++i])
	{
		free((*data)->splited_str[i]);
		(*data)->splited_str[i] = 0;
	}
	free((*data)->splited_str);
	(*data)->splited_str = 0;
	free((*data)->joined_str);
	(*data)->joined_str = 0;
	free(*data);
	*data = NULL;
}

void	free_list(t_stack **list_a, t_stack **list_b)
{
	t_stack	*tmp;

	while (*list_a)
	{
		tmp = (*list_a)->next;
		free(*list_a);
		(*list_a) = tmp;
	}
	free(*list_a);
	while (*list_b)
	{
		tmp = (*list_b)->next;
		free(*list_b);
		(*list_b) = tmp;
	}
	free(*list_b);
}

void	alg(t_stack **list_a, t_stack **list_b, t_data *data)
{
	data->splited_str = ft_split(data->joined_str, ' ');
	if (!data->splited_str[0])
		return ;
	check_char(data->splited_str);
	check_valid(data->splited_str);
	fill_list(list_a, data->splited_str, &data->len);
	check_dublicates(list_a);
	issorted_detals(list_a, list_b, data);
}

int	main(int ac, char **av)
{
	t_data			*data;
	t_stack			*list_a;
	t_stack			*list_b;

	list_a = NULL;
	list_b = NULL;
	data = malloc(sizeof(t_data));
	data->joined_str = NULL;
	data->splited_str = 0;
	if (ac > 1)
	{
		data->i = 1;
		while (av[data->i])
		{
			data->joined_str = ft_strjoin(data->joined_str, av[data->i]);
			data->joined_str = ft_strjoin(data->joined_str, " ");
			data->i++;
		}
		alg(&list_a, &list_b, data);
		free_list(&list_a, &list_b);
	}
	free_data(&data);
	return (0);
}
