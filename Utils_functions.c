/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-pin <ddel-pin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:18:19 by ddel-pin          #+#    #+#             */
/*   Updated: 2025/04/22 16:34:45 by ddel-pin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split_array)
{
	int	i;

	i = 0;
	if (!split_array)
		return ;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

int	push_swap_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

int	check_sorted(int *pile, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (pile[i - 1] > pile[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (pile[i - 1] < pile[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_doubles(t_piles *pile)
{
	int	i;
	int	j;

	i = 0;
	while (i < pile->size_a)
	{
		j = i + 1;
		while (j < pile->size_a)
		{
			if (pile->a[i] == pile->a[j])
				error_detected(pile);
			j++;
		}
		i++;
	}
}
